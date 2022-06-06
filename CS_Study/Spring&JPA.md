# Spring 요약


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
<summary><b>Spring Boot 장점, 특징</b></summary>
<div markdown="1">

* 자주 사용되는 라이브러리들의 버전 관리 자동화
    * maven이나 gradle 등과 같은 빌드 도구에 버전을 명시하지 않아도 적합한 라이브러리 버전을 찾아서 가져와 줌
* AutoConfig로 복잡한 설정 자동화
    * 
* 내장 웹서버 제공
* 실행 가능한 JAR로 개발 가능

</div>
</details>


<details>
<summary><b>Spring Framework와 Spring Boot의 차이점</b></summary>
<div markdown="1">

* Spring Boot에는 Tomcat이 내장(**Embedded Tomcat**)되어 있어 애플리케이션을 바로 실행할 수 있다.
    * build된 스프링부트 애플리케이션 jar또는 war 파일을 java 명령어로 바로 실행가능
    * 반면, Spring은 **외장 Tomcat**을 설치하고 실행환경을 구축해 주어야 한다.
* 


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
<summary><b>Filter, Interceptor, AOP</b></summary>
<div markdown="1">

* [출처](https://baek-kim-dev.site/61)
* Interceptor와 Filter는 Servlet 단위에서 실행된다. 반면 AOP는 메소드 앞에 Proxy패턴의 형태로 실행된다.
* 실행순서를 보면 Filter가 가장 밖에 있고 그안에 Interceptor, 그안에 AOP가 있는 형태
* ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F1bEhb%2FbtqH8cRq0sY%2FdQVkF7pbrdOTVnILW7bmzK%2Fimg.png)


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
<summary><b>Rabbit MQ</b></summary>
<div markdown="1">

* Rabbit MQ UI를 통해 큐를 생성
* Gradle에 Rabbit MQ 의존성을 추가하고 야믈파일에 Rabbit MQ에 대한 Port설정과 큐에 대한 정보를 입력
* 기존에는 API요청에 대한 내용을 받아서 JPA로 바로 처리했었지만 Rabbit MQ를 통해 메시지를 처리할 수 있도록 수정했음
* Producer와 Consumer를 주입받아 서 메시지를 처리했는데
* 이때, 메시지를 Json에서 String으로 바꿔서 넣어줘야 하기 때문에 Jackson 라이브러리의 ObjectMapper를 주입받아 사용했다.
* 그럼 Producer를 통해 메시지큐에 요청에 대한 내용이 push되고 Consumer를 통해 작성해둔 메소드가 수행되는 식
* 메소드가 수행될때 큐의 요청 내용이 JPA를 통해 DB에 반영되거나 조회할 수 있는것임

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
<summary><b>디스패처 서블릿(Dispatcher Servlet) 이란?</b></summary>
<div markdown="1">

* 디스패처 서블릿을 통해 요청을 처리할 컨트롤러를 찾아서 위임하고, 그 결과를 받아옴

</div>
</details>


<details>
<summary><b>Filter와 Interceptor</b></summary>
<div markdown="1">

* 

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
<summary><b>Spring AOP란?</b></summary>
<div markdown="1">

* Spring AOP는 Proxy를 기반으로 한 Runtime Weaving 방식이다
* Spring AOP에서는 JDK Dynamic Proxy 와 CGlib 을 통해 Proxy화 한다
    * JDK Dynamic Proxy는 Reflection을 기반으로 이루어지고
    * CGlib 은 상속을 기반으로 이루어진다

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


* self invocation ?