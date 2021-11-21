## web 지식들 -> 나중에 따로 빼서 정리하기

### web : 월드 와이드 웹(World Wide Web, WWW, W3)을 줄여 간단히 웹이라 부름

### HTTP 웹지식

<br><br>

### Web 서버와 Web Application Server의 차이점 ?
web서버는 정적리소스만 관리
WAS:Web Application Server 는 동적인 리소스도 관리

<br><br>

### WAS(Web Application Server) 란?
![](2021-09-07-23-26-26.png)

<br><br>

### Servlet 이란?
![](2021-09-07-23-28-23.png)
![](2021-09-07-23-29-52.png)

<br><br>

### MVC패턴 in servlet
![](2021-09-07-23-33-43.png)

<br><br>

### Servlet의 Life Cycle
각각의 요청마다 하나의 스레드로 실행됨
스레드마다 servlet의 인스턴스가 생성되는것이 아니라, 컨테이너에 멀티스레드 요청이 오고 서블릿이 해당 멀티스레드에 대한 요청을 처리함.

Each request runs in a separate thread !
The container runs multiple threads to process multiple request to a single servlet.

![](2021-09-07-23-40-26.png)

<br><br>

### Front Controller Pattern - **Dispatcher Servlet**

![](2021-09-09-01-18-00.png)
![](2021-09-09-01-19-00.png)
![](2021-09-09-01-21-13.png)

<br><br>

### Spring MVC 처리 흐름
![](2021-09-09-01-24-39.png)
    1. DispatcherServlet의 HTTP 요청 접수
    2. DispatcherServlet에서 컨트롤러로 HTTP 요청 위임
    3. 컨트롤러의 모델 생성과 정보 등록
    4. 컨트롤러의 결과 리턴: 모델과 뷰
    5. DispatcherServlet의 뷰 호출과 (6) 모델 참조
    6. HTTP 응답 돌려주기

<br><br>

### Web Application Context
ApplicationContext를 상속하는 클래스임
Servlet에 접근할 수 있는 기능이 추가된 Application Context임

<br><br>

**ServletContext**
아래그림에서 ServletContext는 Servlet Container에 의해서 만들어짐
여러 Servlet의 정보가 담겨 있어 공유가 가능함
![](2021-09-13-17-22-02.png)

위의 그림에서 Application Context는 **루트Application Context**인데,
**루트 Application Context**에는 모든 Application Context가 접근이 가능함 -> 어떻게 ?
Servlet Context가 만들어질때 **루트 Application Context**도 생성되는데
모든 Dispatcher Servlet들은 ServletContext을 통해 **루트 Application Context**로 접근하여 등록된 Bean을 가져올 수 있음
즉, **루트 Application Context**와 다른 Application Context의 차이점은 ServletContext가 접근이 가능한지 아닌지의 차이임

자세한 동작방식은 6주차 3일차의 2번째 강의내용 확인

<br><br>

### REST(ful) API
REST를 만족하는 API 라는 뜻
REST API = **REST 아키텍쳐 스타일**을 따르는 API

* REST 아키텍쳐 스타일
1. 클라이언트 서버
2. 스테이트리스
3. 캐시
4. 균일한 인터페이스
5. 계층화된 시스템

<br>

#### Richardson Maturity Model
![](2021-09-14-00-27-11.png)


<br><br>

### 일반 웹 애플리케이션 & 단일 페이지 웹 애플리케이션
![](2021-09-14-00-26-39.png)

<br><br>

### CORS란 ?

preflight ?

<br><br>

