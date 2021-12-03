# 예외 처리

***

## 오류 페이지, API 예외처리
* 오류 페이지는 4xx, 5xx와 같은 오류 페이지만 있으면 BasicErrorController를 이용하여 대부분 해결가능
* API 예외처리의 경우는 복잡함
    * API는 각 오류 상황에 맞는 오류 응답 스펙을 정하고, JSON으로 데이터를 내려주어야 한다.
    * 기업간의 API통신이라던지, MSA구조에서의 API통신과 같은 상황에서 오류 응답 스펙이 공유되어야 함

<br>

******
### 1. 스프링이 아닌 순수 서블릿 컨테이너는 예외가 어떻게 처리될 수 있을까?
1. Exception(예외)가 발생하여 서블릿 밖으로 전달됨
    * 예외 발생 흐름 -> `WAS(여기까지 전파) <- 필터 <- 서블릿 <- 인터셉터 <- 컨트롤러(예외발생)`

2. response.sendError(HTTP 상태코드, 오류 메시지)가 호출 되었을때 설정된 오류 페이지를 찾음
    * sendError 흐름 -> `WAS(sendError 호출 기록 확인) <- 필터 <- 서블릿 <- 인터셉터 <- 컨트롤러(response.sendError())`

* 어떻게 오류 페이지를 찾을까 ?
    * WAS는 해당 예외를 처리하는 오류 페이지 정보를 확인한다.
    * `new ErrorPage(RuntimeException.class, "/error-page/500");`
    * 위 코드의 경우 RuntimeException일때 /error-page/500에 해당하는 페이지(컨트롤러)를 찾음

* 즉, 정리하면
1. 예외가 발생해서 WAS까지 전파된다.
2. WAS는 오류 페이지 경로를 찾아서 내부에서 오류 페이지를 호출한다. 이때 오류 페이지 경로로 필터,
서블릿, 인터셉터, 컨트롤러가 모두 다시 호출된다.

* 중요한 점은 웹 브라우저(클라이언트)는 **서버 내부에서 이런 일이 일어나는지 전혀 모른다는 점**이다. 오직
서버 내부에서 오류 페이지를 찾기 위해 추가적인 호출을 한다.




<br> <br>

******
### 2. 스프링이 아닌 순수 서블릿 컨테이너에서 예외 흐름 정리
* `/hello` 라는 정상요청이 오면 ?
WAS("/hello", dispatchType=REQUEST) -> 필터 -> 서블릿 -> 인터셉터 -> 컨트롤러 -> View

* `/error-ex` 라는 오류 요청이 오면 ?
    * 위에서 설명한 정상요청 이후 오류에 의해 중복요청이 오기때문에 filter나 인터셉터가 다시 수행됨
    * 자세한 내용은 MVC2의 `서블릿 예외처리 필터/인터셉터` 참고
        > 필터(`순수 servlet 기술`)는 DispatchType 으로 중복 호출 제거 ( dispatchType=REQUEST )
        > 인터셉터(`spring boot 기술`)는 경로 정보로 중복 호출 제거( excludePathPatterns("/error-page/**") )
    1. WAS(/error-ex, dispatchType=REQUEST) -> 필터 -> 서블릿 -> 인터셉터 -> 컨트롤러
    2. WAS(여기까지 전파) <- 필터 <- 서블릿 <- 인터셉터 <- 컨트롤러(예외발생)
    3. WAS 오류 페이지 확인
    4. WAS(/error-page/500, dispatchType=ERROR) -> 필터(x) -> 서블릿 -> 인터셉터(x) ->
    컨트롤러(/error-page/500) -> View




<br> <br>

******
### 3. 스프링부트를 이용한 오류페이지
* `/error` 라는 페이지를 default로 ErrorPage 자동등록
* 특정 오류에 대해 페이지를 지정해 주지 않으면 모두 `/error`로 자동등록
* `/error`에 대한 컨트롤러는 **BasicErrorController**라는 컨트롤러를 자동 등록
    * BasicErrorController : ErrorPage에서 등록된 `/error`를 매핑해서 처리하는 컨트롤러임
* 에러 페이지에 대한 기본 컨트롤러인 BasicErrorController는 로직이 자세하게 구현이 되어 있기 때문에
개발자는 **오류 페이지 화면만** BasicErrorController가 제공하는 룰과 우선순위에 따라서 등록하면 됨

* 뷰 선택 우선순위
    > BasicErrorController 의 처리 순서
1. 뷰 템플릿 (동적) -> @ResponseBody 처럼 동적인 데이터 있을때
    * ex) resources/templates/error/500.html
    * ex) resources/templates/error/5xx.html
2. 정적 리소스( static , public )
    * ex) resources/static/error/400.html
    * ex) resources/static/error/404.html
    * ex) resources/static/error/4xx.html
3. 적용 대상이 없을 때 뷰 이름( error )
    * resources/templates/error.html

해당 경로 위치에 HTTP 상태 코드 이름의 뷰 파일을 넣어두면 된다.
뷰 템플릿이 정적 리소스보다 우선순위가 높고, 404, 500처럼 구체적인 것이 5xx처럼 덜 구체적인 것 보다
우선순위가 높다.
5xx, 4xx 라고 하면 500대, 400대 오류를 처리해준다.

**스프링 부트가 기본으로 제공하는 오류 페이지를 활용하면 오류 페이지와 관련된 대부분의 문제는 손쉽게 해결할 수 있다.**



<br> <br>

******
### 4. BasicErrorController가 제공하는 기본 정보들
BasicErrorController 컨트롤러는 다음 정보를 model에 담아서 뷰에 전달한다. 
뷰 템플릿은 이 값을 활용해서 출력할 수 있다.

* 예시
~~~
* timestamp: Fri Feb 05 00:00:00 KST 2021
* status: 400
* error: Bad Request
* exception: org.springframework.validation.BindException
* trace: 예외 trace
* message: Validation failed for object='data'. Error count: 1
* errors: Errors(BindingResult)
* path: 클라이언트 요청 경로 (`/hello`)
~~~

* 실무에서는 위의 오류 내용들을 노출하면 안되고 서버에 로그를 남겨서 로그를 확인해야 한다.


<br> <br>

******
### 5. API 예외처리
* API는 각 오류 상황에 맞는 오류 응답 스펙을 정하고, JSON으로 데이터를 내려주어야 한다.
* 1. ~ 4. 에 관한 내용들은 오류 페이지를 요청하기 위해 HTTP Header에 Accept가 text/html 이었음
* request의 HTTP Header에 Accept 가 application/json일 경우 **BasicErrorController**의 API 예외 컨트롤러를 호출할 수 있음
* 



<br> <br>

******
### 6. 



<br> <br>

******
### 7. 



<br> <br>

******
### 8. 



<br> <br>

******
### 9. 



<br> <br>

******
### 10. 

