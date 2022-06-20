# Spring 요약

<details>
<summary><b>프레임워크와 라이브러리의 차이점</b></summary>
<div markdown="1">

* 라이브러리와 프레임워크의 차이는 제어 흐름에 대한 주도성이 누구에게/어디에 있는가에 있음.
* 즉, 어플리케이션의 Flow를 누가 쥐고 있느냐에 달려 있음
* 개발자가 아닌 프레임워크가 어플리케이션의 흐름을 제어함(IoC)

</div>
</details>


<details>
<summary><b>Spring Framework의 특징</b></summary>
<div markdown="1">

* [출처](https://zzdd1558.tistory.com/172)
~~~
IoC, DI 등 스프링의 특징이 개발자가 전체적으로 신경써야할 부분에 대해서 스트레스를 줄여줌
비지니스 로직에 집중할 수 있기 때문에 생산성 향상됨
~~~

* 경량 컨테이너로서 자바 객체를 직접 관리한다. 
    * 각각의 객체 생성, 소멸과 같은 라이프 사이클을 관리하며 언제든 스프링으로부터 필요한 객체를 얻어올 수 있다.
* 제어 반전(IoC : Inversion of Control)을 지원한다. 
    * 컨트롤의 제어권이 사용자가 아니라 프레임워크에 있어서 필요에 따라 스프링에서 사용자의 코드를 호출
    * 객체들 간의 느슨한 결합을 유지할 수 있다.
* 의존성 주입(DI : Dependency Injection)을 지원
    * 각각의 계층이나 서비스들 간에 의존성이 존재할 경우 프레임워크가 알아서 주입해준다.
    * 클래스 내부에서 의존관계 있는 다른 구현체들을 호출하는것이 아니라 외부에서 즉, Spring 컨테이너가 설정정보를 통해 주입을 해 줌
* 관점 지향 프로그래밍(AOP : Aspect-Oriented Programming)을 지원
    * 트랜잭션이나 로깅, 보안과 같이 여러 모듈에서 공통적으로 사용하는 기능의 경우 해당 기능을 분리하여 관리할 수 있다.
* POJO(Plain Old Java Object) 방식의 프레임워크
    * 별도의 API를 사용하지 않는 setter, getter 메서드로 이루어진 단순한 자바 오브젝트
    * 순수한 자바 오브젝트이기 때문에 환경과 기술에 종속되지 않음
* 확장성이 높다. 
    * 필요시 다양한 라이브러리를 스프링에서 이용할 수 있다.

</div>
</details>


<details>
<summary><b>Spring Boot 장점, 특징, Spring과 차이점</b></summary>
<div markdown="1">

* 라이브러리들의 버전 관리 자동화
    * maven이나 gradle 등과 같은 빌드 도구에 버전을 명시하지 않아도 적합한 라이브러리 버전을 찾아서 가져와 줌
* 설정의 자동화
    * 개발에 필요한 라이브러리들을 추가하면 스프링 부트가 이 라이브러리들을 인지해서 관련된 스프링 설정을 자동으로 처리
* Spring Boot에는 Tomcat이 내장(**Embedded Tomcat**)되어 있어 애플리케이션을 바로 실행할 수 있다.
    * 애플리케이션 빌드후 패키징된 jar또는 war 파일을 java 명령어로 독립적으로, 바로 실행가능
    * 반면, Spring은 **외장 Tomcat**을 설치하고 실행환경을 구축해 주어야 한다.

</div>
</details>


<details>
<summary><b>Apache Tomcat 이란</b></summary>
<div markdown="1">

* 아파치 소프트웨어 재단에서 개발한 서블릿 컨테이너(또는 웹 컨테이너)만 있는 웹 어플리케이션 서버(WAS)이다.
* 웹 서버와 연동하여 실행할 수 있는 자바 환경을 제공한다.
* 즉, JSP(Java Server Pages)와 Servlet이 실행할 수 있는 환경을 제공.

* 요청을 늦게 응답할수록, 해당 요청이 톰캣의 쓰레드를 차지하고 있어서 쓰레드가 금방 고갈되는 이슈가 있음
* 요청을 가능하면 빠르게 처리하고 응답을 주어야 함 -> 쓰레드가 다시 다른 요청을 처리할 수 있는 상태가 됨

* ----미완----

</div>
</details>


<details>
<summary><b>서블릿, 디스패처 서블릿(Dispatcher Servlet), 서블릿 컨테이너, 스프링 컨테이너 ?</b></summary>
<div markdown="1">

#### [참고링크](https://taes-k.github.io/2020/02/16/servlet-container-spring-container/)
* 스프링에서는 아래와 같은 구조를 통해 클라이언트와 통신함
![](https://taes-k.github.io/images//posts/2020-02-16-servlet-container-spring-container/1.png)

<br>

### 서블릿(Servlet)과 디스패처 서블릿(Dispatcher Servlet)
* 서블릿은 웹 기반의 요청에 대해 **동적으로** 처리해주는 역할을 함. (Servlet Container에서 동작함)
* **Spring MVC** 에서는 디스패처 서블릿이라는 모든 요청을 담당하는 서블릿을 두고 컨트롤러에 위임을 하여 요청을 처리함
* 즉, **디스패처 서블릿(Dispatcher Servlet)** 은 제일 앞에서 서버로 들어오는 모든 요청을 처리하는 Front Controller임(=Front Controller 패턴)
* 디스패처 서블릿 역시 Servlet Container에서 동작함
![](https://taes-k.github.io/images//posts/2020-02-16-servlet-container-spring-container/2.png)

<br>

* 기존에는 Servlet을 통해 URL 매핑을 활용해 web.xml에 모두 등록해야 했음(또는 `@SpringBootApplication` 어노테이션 사용)
* 디스패처 서블릿이 생기고 어플리케이션으로 들어오는 모든 요청을 핸들링 할 수 있게 됨
* 즉, Controller로 향하는 모든 웹 요청의 진입점으로써 요청을 처리하고 결과를 클라이언트에게 응답해 주는 역할을 함
* 디스패처 서블릿을 이용한다는 것은 Spring MVC를 이용하겠다는 뜻임

<br>

### 서블릿 컨테이너
* 서블릿 컨테이너라는 말 그대로 서블릿을 관리하는 역할을 함
    1. 서블릿의 라이프 사이클(생성, 실행, 파괴 등)을 직접적으로 관리해주는 역할을 함
    2. 웹서버와의 통신을 통해 클라이언트의 request를 전달받아 동적 서비스를 response를 해야하는데, 
        해당 과정에서 **웹서버와 소켓을 만들어 통신** 함
    3. 클라이언트 요청이 들어올때 쓰레드를 생성하여 요청을 처리. 해당 쓰레드는 서블릿 컨테이너에서 쓰레드풀을 별도로 관리하여 실행

<br>

### 스프링 컨테이너
* 아래의 그림을 보면 디스패처 서블릿안에 Servlet WebApplicationContext와 Root WebApplicationContext가 동작하는것 처럼 보이지만
* 두 Context는 첫번째 그림에서 Spring Container안에서 동작하는 Context임
![](https://taes-k.github.io/images//posts/2020-02-16-servlet-container-spring-container/4.png)
* 서블릿 컨테이너는 서블릿의 생명주기를 관리했다면,
    스프링컨테이너는 Java object인 빈(Bean)의 라이프 사이클 관리
* Spring 프레임워크의 특징인 IOC(제어역전)와 DI(의존성주입)을 제공해주는 역할을 함

</div>
</details>


<details>
<summary><b>Spring에서의 요청 흐름</b></summary>
<div markdown="1">

* [참고링크](https://taes-k.github.io/2020/02/16/servlet-container-spring-container/)

![](https://taes-k.github.io/images//posts/2020-02-16-servlet-container-spring-container/6.png)

* Spring Boot에서의 클라이언트 요청 처리 과정
    1. Client -> Web server 으로 request 보냄
    2. 동적 Web server -> Servlet container로 전달
    3. Servlet container 쓰레드 생성
    4. DispatcherServlet init (서블릿 생성 안되어 있을경우)
    5. 생성된 쓰레드에서 DispatcherServlet service() 메서드 호출
    6. HandlerMapping을 통해 매핑 컨트롤러 조회
    7. HandlerAdapter를 통해 매핑 컨트롤러에 request 전달
    8. 개발자가 구현한 Controller가 동작

</div>
</details>


<details>
<summary><b>Filter, Dispatcher Servlet, AOP, Controller 호출 순서?</b></summary>
<div markdown="1">

* [출처](https://baek-kim-dev.site/61)
* Interceptor와 Filter는 Servlet 단위에서 실행된다. 반면 AOP는 메소드 앞에 Proxy패턴의 형태로 실행된다.
* 실행순서를 보면 Filter가 가장 밖에 있고 그안에 Interceptor, 그안에 AOP가 있는 형태
* ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F1bEhb%2FbtqH8cRq0sY%2FdQVkF7pbrdOTVnILW7bmzK%2Fimg.png)

</div>
</details>


<details>
<summary><b>필터(Filter)와 인터셉터(Interceptor) 차이</b></summary>
<div markdown="1">

* [참고](https://mangkyu.tistory.com/173)
* **필터**에서는 기본적으로 스프링과 무관하게 전역적으로 처리해야 하는 작업들을 처리할 수 있음
    * 필터는 Web Container 안에서 동작
* **인터셉터**에서는 클라이언트의 요청과 관련되어 전역적으로 처리해야 하는 작업들을 처리할 수 있음
    * 인터셉터는 Spring Container 안에서 동작
* Srping Security 공부후 정리

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fcjsq60%2FbtrzjoZ0qcq%2FEDsLOVpZNcmFu6prkzALFk%2Fimg.png)

</div>
</details>


<details>
<summary><b>Spring AOP란?</b></summary>
<div markdown="1">

* Spring AOP는 Proxy를 기반으로 한 Runtime Weaving 방식이다
* Spring AOP에서는 JDK Dynamic Proxy 와 CGlib 을 통해 Proxy화 한다
    * JDK Dynamic Proxy는 Reflection을 기반으로 이루어지고
    * CGlib 은 상속을 기반으로 이루어진다
* 정리해야 함

</div>
</details>


<details>
<summary><b>JUnit5 ?</b></summary>
<div markdown="1">

* Java 8 부터 지원한다.
    * assertion method와 lamda를 함께 사용할 수 있다.
* Spring Boot 2.2 이후부터 기본으로 제공
* 이전 버전으로 작성된 테스트 코드여도 컴파일이 정상적으로 지원된다.

</div>
</details>


<details>
<summary><b>Lombok의 단점</b></summary>
<div markdown="1">

* 무분별하게 사용하면 많은 코드가 단축되기 때문에 오히려 가독성이 떨어진다.
* 의도치 않은 값이 초기화될 수 있다.
* 양방향 연관관계에서 `@ToString` 을 사용하면 무한 반복에 걸릴 수 있다.
* Setter 같은 경우 무분별하게 열어두면 외부에서 필드값을 변경할 수 있는 수단이 될 수 있기 때문에 주의해서 사용해야 한다.

</div>
</details>


<details>
<summary><b>영속성 컨텍스트란</b></summary>
<div markdown="1">

* 

</div>
</details>


<details>
<summary><b>Dirty Checking</b></summary>
<div markdown="1">

* JPA 에는 Dirty Checking (변경감지) 이라는 개념을 활용할 수 있음
* 개발자가 임의로 UPDATE 쿼리를 사용하지 않아도 JPA가 알아서 업데이트를 해줌
* commit()또는 flush()가 일어날 때 1차캐시에 저장되어 있는 엔티티와 스냅샷을 비교해서, 변경사항이있으면 UPDATE 쿼리를 날려줌

</div>
</details>


<details>
<summary><b>영속성 전이 Cascade</b></summary>
<div markdown="1">

* Cascade 종류
    * ALL: 모두 적용
    * PERSIST : 영속
    * REMOVE  : 삭제
* 보통 Cascade를 사용할때 **저장할때만** Cascade하고 싶으면 **PERSIST**,
* 그렇지 않으면 **ALL** 사용함
* 현업에서는 Cascade사용시 ALL or PERSIST 둘중 하나로 많이 사용
* Parent와 Child클래스의 Life Cycle이 유사할때, Child에 대해서 Parent가 단일 소유자 일때 Cascade 사용
    * 만약 다른곳에서도 사용하는 엔티티라면 별도의 Repository를 생성해서 persist를 따로 하는것이 좋음
    * 즉, 어떤 엔티티에 종속적인 엔티티일때 사용하면 좋음 -> 라이프 사이클이 같기 때문 (ex. Order와 Delivery)
* Cascade의 역할을 단순하게 설명하면, persist() 호출을 줄여주는 역할을 함

* 간단 정리
1. 완전 개인 소유인 경우에 사용할 수 있다. (라이프 사이클 관련)
2. DDD의 Aggregate Root와 어울린다.
3. 애매하면 사용하지 않는다.

</div>
</details>


<details>
<summary><b>N+1 문제</b></summary>
<div markdown="1">

* N+1 문제는 **즉시로딩** 사용시 반드시 일어남 -> 연관관계의 엔티티를 모두 조회하기 때문
* N+1 문제는 **지연로딩** 사용시에도 일어날 수 있음. 아래 예시 참고
* OneToOne, ManyToOne, OneToMany 모두에서 일어날 수 있음

#### 예시
Order와 Member가 `N:1`, Order와 Delivery가 `1:1` 일때,
대충 필요한 데이터를 DTO로 나타내보면

~~~java
class OrderResponse {
    private Long orderId;
    private Member member;
    private Delivery delivery;
}
~~~

모든 Order에 대하여 위와 같은 데이터를 조회한다고 할때 (findAllOrder),
Order에서 Member와 Delivery가 Lazy세팅이 되어 있다면
쿼리 개수는 **최악의** 경우 모든 order를 조회하는 쿼리 **1번**,
그리고 Member와 Delivery를 조회하는 쿼리로 **2번의 쿼리가 order마다** 이루어 진다.
Order의 개수가 N개일 경우 총 쿼리수는 처음에 order조회 1번,
Member조회 N번, Delivery조회 N번으로 **1+N+N**번의 쿼리가 나가게 된다.

* 여기서 **최악의 경우**란, Order Member Delivery관계에서 Order : Member = N : 1 이기 때문에 
각각의 Order마다 다른 Memeber와 연관관계일 경우 최악의 경우에 해당한다.

* **최선의 경우** 조회할 모든 Order의 Member가 같은 경우 하나 조회시 Member는 영속성 컨텍스트에 유지되기 때문에
다음 Order조회부터는 Member조회 쿼리가 발생하지 않게 된다.
따라서 최선의 경우 **1+1+N**번의 쿼리가 발생하게 된다. (모든order 1번, Member 1번, Delivery N번)


> N+1 문제는 fetch join을 이용하면 **쿼리 한번에** 해결할 수 있음 !
> 따라서, 기본적으로 Lazy로딩을 깔아두고, 위의 예시처럼 필요한 경우 fetch join을 쓰는것이 좋은 방법
> 위의 예시에는 없지만 OneToMany에서도 일어날 수 있음

* [N+1 문제와 자세한 해결방법](https://gmoon92.github.io/spring/jpa/hibernate/n+1/2021/01/12/jpa-n-plus-one.html)

</div>
</details>


<details>
<summary><b>Mockito</b></summary>
<div markdown="1">

* 진짜 객체 처럼 동작하지만 프로그래머가 직접 컨트롤 할 수 있는 객체를 만들어서 로직을 검증할 수 있게 해주는 프레임 워크
* Stubbing 이란 ? **Mock객체의 행동**을 조작하는것임
* 예시
    1. 특정 매개변수를 받을 경우 특정한 값을 리턴하거나 예외를 발생시키도록 할 수 있음
    2. Void메소드가 특정 매개변수를 받거나 호출된 경우 예외를 발생시킬 수 있음
    3. 메소드가 동일한 매개변수로 여러번 호출되더라도 호출되는 순서에 따라 다르게 Stubbing가능
* Mock 객체 확인 : Mock 객체가 어떻게 사용이 됐는지 확인하여 로직을 검증할 수 있다.
    * 특정 메소드가 특정 매개변수로 몇번 호출 되었는지, 최소 한번은 호출 됐는지, 전혀 호출되지 않았는지
    * 어떤 순서대로 호출했는지
    * 특정 시간 이내에 호출됐는지
    * 특정 시점 이후에 아무 일도 벌어지지 않았는지 등

</div>
</details>


<details>
<summary><b>@Autowired 와 의존관계 주입방법</b></summary>
<div markdown="1">

* **@Autowired** 를 이용하면 필요한 의존 객체에 해당하는 빈을 찾아 필드 또는 파라미터명에 주입할 수 있다.
* **@Autowired** 는 Spring 컨테이너가 관리하는 Bean에서만 사용이 가능하다.
* **@Autowired** 로 Bean을 매칭하는 방법
    1. 타입 매칭 (같은 타입이거나 그 타입의 자식들을 다 가져옴)
    2. 타입 매칭의 결과가 2개 이상인 경우 **필드명** 또는 **파라미터명** 으로 빈 이름 매칭하여 주입
        * 해당하는 이름의 빈이 없으면 NoUniqueBeanDefinitionException 오류가 발생한다.
    3. 2.와 같이 매칭 결과가 여러개인 경우, 특정 빈을 주입받기 위한 방법 ? 
        * 예시) DiscountPolicy를 상속받는 FixDiscountPolicy, RateDiscountPolicy가 있는데, 
            DiscountPolicy를 주입받는 경우
            ~~~java
            @Component
            public class OrderServiceImpl implements OrderService {
                
                // c.f) 왜 FixDiscountPolicy나 RateDiscountPolicy로 주입받지 않음 ? -> DIP준수 (SOLID와 다형성)
                private final DiscountPolicy discountPolicy;
                private final MemberRepository memberRepository;

                @Autowired
                public OrderServiceImpl(DiscountPolicy discountPolicy, MemberRepository memberRepository){
                    this.discountPolicy = discountPolicy;
                    this.memberRepository = memberRepository;
                }
                // ...
            }
            ~~~
            위와 같은 경우 discountPolicy에 FixDiscountPolicy를 주입하려면 어떻게 해야할까?
            
        * **@Qualifier("name")** 를 이용
            * 빈(클래스)에 **@Qualifier("name")** 를 붙이고 
            * 해당 빈을 주입받을 필드 또는 파라미터에 **@Qualifier("name")** 를 붙여주면 됨
        * **@Primary**
            * 위와 같은 예시의 경우 FixDiscountPolicy 빈에 **@Primary** 를 붙여주면
            * 위 코드와 같은 경우 DiscountPolicy에 FixDiscountPolicy빈이 주입이 됨
        * **@Primary** 와 **@Qualifier("name")** 를 모두 활용하여 깔끔하게 빈을 관리할 수 있다.
            * 메인 데이터베이스의 커넥션을 획득하는 스프링빈과 특별한 기능으로 가끔 사용하는 데이터베이스의 커넥션을 획득하는 스프링빈이 있음
            * 메인 데이터베이스의 스프링빈은 **@Primary** 를 사용
            * 서브 데이터베이스의 스프링빈은 **@Qualifier("name")** 를 사용
        * **@Primary** 와 **@Qualifier** 의 우선순위는 **@Qualifier** 가 더 높다.

<br>

* **@Autowired** 를 이용한 의존관계 주입방법
    1. 생성자 주입
        * 불변, 필수적인 의존관계에 있을때 효과적
        * 생성자가 하나인 경우 **@Autowired** 생략가능
    2. 수정자(Setter) 주입
        * 선택, 변경 가능성이 있는 의존관계에 사용
    3. 필드 주입
        * DI 컨테이너에 의존적인 방법
        * 실제 어플리케이션 코드에는 적용하지 않는것이 좋음
        * Test코드 작성시에는 유용함

<br>

* 롬복을 이용한 자동 의존관계 주입
    * 막상 개발해 보면 대부분 불변의 의존관계를 가짐
    * 불변의 관계의 경우 final을 사용함
    * 위와 같은 상황에서 생성자 주입방법과 Lombok의 **@RequiredArgsConstructor** 를 이용하면 코드를 깔끔하게 줄일 수 있음 ("**@Autowired** 로 Bean을 매칭하는 방법"에서의 예시코드와 비교)
        ~~~java
        @Component
        @RequiredArgsConstructor
        public class OrderServiceImpl implements OrderService {
            
            private final DiscountPolicy discountPolicy;
            private final MemberRepository memberRepository;

            // 아래의 코드를 생략할 수 있음
            //@Autowired
            //public OrderServiceImpl(DiscountPolicy discountPolicy, MemberRepository memberRepository){
            //    this.discountPolicy = discountPolicy;
            //    this.memberRepository = memberRepository;
            //}
            // ...
        }
        ~~~

</div>
</details>

* Todo
    * self invocation ?
    * jpa에서 Repository를 이용한 비관적락
    * [Access Token 저장위치](https://velog.io/@neity16/NodeJS-Token-%EC%A0%80%EC%9E%A5-%EC%9C%84%EC%B9%98%EC%9D%98-%EA%B3%A0%EC%B0%B0)