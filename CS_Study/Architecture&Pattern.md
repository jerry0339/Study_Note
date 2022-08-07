# Architecture

<details>
<summary><b>좋은 코드란?</b></summary>
<div markdown="1">

* 좋은 코드란 좋은 기능을 제공하고 좋은 구조적 품질을 가진 코드이다.

<br>

* 좋은 기능을 제공하는 코드란?
    * 기능적으로 사용자가 만족할 수 있는 서비스를 제공할 수 있어야 함
    * 예를들어 편리한 기능을 제공하거나 빠른 응답시간을 제공하는 서비스

<br>

* **좋은 구조적 품질을 가진 코드란 ?**
    * 아키텍처가 잘 설계된 코드
    * 가독성이 좋은 코드
    * 확장성 있는 코드
    * 유지보수성, 재사용성이 높은 코드
    * 높은 응집도와 낮은 결합도,의존성을 가지는 코드
    
* **확장성** 있는 코드란 ?
    * 기존 로직에 새로운 값들이 추가, 삭제될 때 내부적으로 변경이 적은 코드
    * 즉, 변경과 확장에 용이한 코드
* **응집도** 란 ?
    * 코드의 한 요소가 해당 기능을 수행하기 위해 얼마만큼의 연관된 책임과 아이디어가 뭉쳐져 있는지 나타내는 정도
    * 일반적으로 특정 목적을 위해 밀접하게 연관된 기능들이 모여서 구현되어 있고, 지나치게 많은 일을 하지 않으면 응집도가 높은것
* **결합도** 란 ?
    * 코드의 한 요소가 다른 것과 얼마나 강력하게 연결되어 있는지, 또한 얼마나 의존적인지 나타내는 정도
* 높은 응집도와 낮은 결합도를 가지는 구조 예시
    * DDD 계층화된 시스템 구조 (Controller, Service, Repository...)
* 따라서 낮은 결합도와 높은 응집도를 가지면서 확장성이 높은 코드는 유지보수성이 좋고 재사용성이 뛰어나기 때문에, 
    좋은 구조적 코드라고 할 수 있다.

</div>
</details>


<details>
<summary><b>객체 지향 프로그래밍의 특징</b></summary>
<div markdown="1">

1. 추상화(abstraction)
    * 객체들의 공통적인 특징(기능, 속성)을 도출하는 것
    * 객체지향적 관점에서는 클래스를 정의하는 것을 추상화라고 할 수 있음
2. 캡슐화(encapsulation)
    * 객체가 독립적으로 역할을 할 수 있도록 데이터와 기능을 하나로 묶어 관리
    * 실제로 구현되는 부분을 외부에 드러나지 않도록 하여 정보를 은닉
    * 외부와 상호작용을 할 때는 메소드를 이용하여 통신할 수 있음
3. 상속성(inheritance)
    * 기존 코드를 재활용해서 사용가능 함
4. 다형성(polymorphism)
    * 여러 형태를 받아들일 수 있는 성질
    * 다른 방법으로 동작하는 함수를 동일한 이름으로 호출 가능
    * ex) 오버라이딩(Overriding), 오버로딩(Overloading)
5. 동적바인딩(Dynamic Binding)
    * 런타임에 호출될 함수가 결정됨 (cf. 정적바인딩 : 컴파일 시점에 호출될 함수가 결정)
    * 가상 함수(오버라이드된 함수)를 호출하는 코드를 컴파일할 때, 바인딩을 실행시간에 결정하는 것
    * 동적 바인딩을 통해 다형성 실현

</div>
</details>


<details>
<summary><b>SOLID(객체 지향 설계)란 ?</b></summary>
<div markdown="1">

* [위키백과](https://ko.wikipedia.org/wiki/SOLID_(%EA%B0%9D%EC%B2%B4_%EC%A7%80%ED%96%A5_%EC%84%A4%EA%B3%84))
* SRP : 단일 책임 원칙 (Single responsibility principle)
    * 한 클래스는 하나의 책임만 가져야 한다.
* OCP : 개방-폐쇄 원칙 (Open/closed principle)
    * 소프트웨어 요소는 확장에는 열려 있으나 변경에는 닫혀 있어야 한다.
* LSP : 리스코프 치환 원칙 (Liskov substitution principle)
    * 프로그램의 객체는 프로그램의 정확성을 깨뜨리지 않으면서 하위 타입의 인스턴스로 바꿀 수 있어야 한다.
* ISP : 인터페이스 분리 원칙 (Interface segregation principle)
    * 특정 클라이언트를 위한 인터페이스 여러 개가 범용 인터페이스 하나보다 낫다.
* DIP : 의존관계 역전 원칙 (Dependency inversion principle) 
    * 추상화에 의존해야지, 구체화에 의존하면 안된다.
    * 의존성 주입은 이 원칙을 따르는 방법 중 하나이다.
    * 예시
        ~~~java
        @Component
        @RequiredArgsConstructor
        public class OrderServiceImpl implements OrderService {
            
            // DiscountPolicy를 상속받는 FixDiscountPolicy와 RateDiscountPolicy 가 있음
            private final DiscountPolicy discountPolicy; 
            private final MemberRepository memberRepository;
        }
        ~~~

</div>
</details>


<details>
<summary><b>싱글톤(Singleton) 패턴이란 ?</b></summary>
<div markdown="1">

* 싱글톤 패턴이란 어떤 객체의 인스턴스로 오직 1개만 생성하여 사용하는 패턴을 의미한다.
* 장점
    * 인스턴스가 한개만 존재하는 것을 보증하고 싶을때 사용할 수 있다.
    * 다른 클래스의 인스턴스들이 싱글톤 인스턴스의 데이터를 공유하는 것이 가능하다.
* 단점
    * 멀티스레드 환경에서 동기화 처리를 해 주어야 함
    * OCP를 준수하지 못한다.
        * 많은 데이터를 공유할 경우, 다른 클래스들 간의 결합도가 높아지므로
* Spring Bean, 데이터베이스에서의 커넥션풀(DBCP), 스레드풀, 캐시, 로그 기록 객체 등에서 사용된다.
* 멀티스레드 환경에서 안전한 싱글톤 만드는 방법
    * [여러가지 방법](https://readystory.tistory.com/116)이 있지만, 가장 보편적인 방법은 아래와 같다.
    * Bill Pugh Singleton Implementaion
        * Bill Pugh가 고안한 방식으로, static inner class를 사용하는 방식
        * static inner class는 Singleton 클래스가 Load 될 때에도 Load 되지 않음
        * getInstance()가 호출됐을 때 비로소 JVM 메모리에 로드되고, 인스턴스를 생성 (지연로딩)
        * 객체를 한 번만 생성하는것을 JVM이 보장
        * 동기화 처리를 JVM에 위임
        * 구현이 간단함
        * 코드
        ~~~java
        public class Singleton {
            private Singleton(){}
            
            private static class SingletonHelper{
                private static final Singleton INSTANCE = new Singleton();
            }
            
            public static Singleton getInstance(){
                return SingletonHelper.INSTANCE;
            }
        }
        ~~~

</div>
</details>


<details>
<summary><b>스트레티지(Strategy) 패턴이란 ?</b></summary>
<div markdown="1">

* [출처](https://gmlwjd9405.github.io/2018/07/06/strategy-pattern.html)
* 행위를 클래스로 캡슐화해 동적으로 행위를 자유롭게 바꿀 수 있게 해주는 패턴
* 즉, 전략을 쉽게 바꿀 수 있도록 해주는 디자인 패턴
* 예시를 보면 한번에 이해됨
    ![](https://gmlwjd9405.github.io/images/design-pattern-strategy/strategy-solution.png)

</div>
</details>


<details>
<summary><b>스테이트(State) 패턴이란 ?</b></summary>
<div markdown="1">

* 객체 내부의 상태가 바뀜에 따라 객체의 행동을 바꿀 수 있는 패턴
* if/else, switch 같은 분기문을 이용하면 쉽게 객체의 상태의 따라 행동을 변화시킬 수 있다.
    * 하지만 새로운 상태를 추가하기 어렵고, 새로운 상태가 추가된다면 많은 메서드를 변경해 주어야 함
    * 유지보수가 어려운, OCP에 위반하는 방법인 것
* 클래스를 활용하거나 enum을 활용하여 해결할 수 있음
    * [Java Enum 활용기](https://techblog.woowahan.com/2527/)

</div>
</details>


<details>
<summary><b>프론트 컨트롤러(Front Controller) 패턴이란?</b></summary>
<div markdown="1">

* 요청마다 해당하는 Controller에 서블릿을 정의해주는 것은 핸들러마다 공통된 로직을 중복 작성할 필요가 있음
* 프론트 컨트롤러는 이러한 공통된 로직을 처리해 주는 역할을 함
* 공통 코드 처리가 가능가 가능하여 Front Controller 외 다른 Controller에서 Servlet 사용하지 않아도 된다.
* 각 클라이언트들은 Front Controller에 요청을 보내고 Front Controller은 각 요청에 맞는 컨트롤러를 찾아서 호출시킨다.
* 공통 코드에 대해서는 Front Controller에서 처리하고, 서로 다른 코드들만 각 Controller에서 처리할 수 있도록 한다.
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FbmIMRX%2Fbtq4rdbwCtY%2FO88ME95Pvv9svLKftxsaU0%2Fimg.png)
* 자세한 내용은 [Spring&JPA,md](https://github.com/jerry0339/Study_Note/blob/master/CS_Study/Spring%26JPA.md)의 Dispatcher Servlet 참고

</div>
</details>


<details>
<summary><b>프록시(Proxy) 패턴이란?</b></summary>
<div markdown="1">

* 

</div>
</details>


<details>
<summary><b>퍼사드 패턴(Facade Pattern)이란 ?</b></summary>
<div markdown="1">

* 퍼사드는 건물의 정면을 의미한다. 디자인 패턴중 하나이다.
* 퍼사드는 클래스 라이브러리 같은 어떤 소프트웨어의 다른 커다란 코드 부분에 대한 간략화된 인터페이스를 제공하는 객체이다.
* 퍼사드는 공통적인 작업에 대해 간편한 메소드들을 제공한다.
![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/56/UML_DP_Fa%C3%A7ade.png/330px-UML_DP_Fa%C3%A7ade.png)
* 코드 예시 : [출처](https://ko.wikipedia.org/wiki/%ED%8D%BC%EC%82%AC%EB%93%9C_%ED%8C%A8%ED%84%B4)
    * 컴퓨터 전원을 킬때 필요한 작업들(메소드)를 퍼사드로 한번에 처리
    ~~~java
    /* Complex parts */
    class CPU {
        public void freeze() { ... }
        public void jump(long position) { ... }
        public void execute() { ... }
    }

    class Memory {
        public void load(long position, byte[] data) {
            ...
        }
    }

    class HardDrive {
        public byte[] read(long lba, int size) {
            ...
        }
    }

    /* Facade */
    class Computer {
        public void startComputer() {
            CPU cpu = new CPU();
            Memory memory = new Memory();
            HardDrive hardDrive = new HardDrive();
            cpu.freeze();
            memory.load(BOOT_ADDRESS, hardDrive.read(BOOT_SECTOR, SECTOR_SIZE));
            cpu.jump(BOOT_ADDRESS);
            cpu.execute();
        }
    }

    /* Client */
    class You {
        public static void main(String[] args) throws ParseException {
            Computer facade = /* grab a facade instance */;
            facade.startComputer();
        }
    }
    ~~~

</div>
</details>


<details>
<summary><b>빌더 패턴이란 ?</b></summary>
<div markdown="1">

* 빌더 패턴 장점
    * 필요한 데이터만 설정할 수 있음
    * 유연성을 확보할 수 있음 (필드가 추가되어도 기존의 모든 코드를 수정하지 않아도 된다.)
    * 가독성을 높일 수 있음
    * 불변성을 확보할 수 있음
* 단점 으로는 파라미터가 늘어날수록 코드를 읽기가 힘들다는 점에서 오히려 가독성이 떨어질 수 있다.

</div>
</details>


<details>
<summary><b>DDD란, MSA란 ?</b></summary>
<div markdown="1">

* DDD란 ?
* DDD란 도메인을 주도로 하여 아키텍처를 설계하는 방식
* 도메인이란 어떠한 유사한 업무나 목적을 가진 집합
* 온라인 서점 이라는 도메인을 예로들면 하위 도메인으로 상품, 회원, 배송 등등의 도메인으로 나뉠 수 있다.
* 도메인은 서로 철저히 분리되고, **높은 응집력**과 **낮은 결합도**로 **변경과 확장에 용이**한 설계를 얻게 됩니다.
* 규모가 커질수록 구조와 코드가 복잡해지고 어플리케이션이 무거워진다는 단점이 있음

* MSA란 ?
* 여러 모듈(경량화되고 독립적인 서비스)을 조합하여 애플리케이션을 구현
* 모듈마다 자체 DB를 가지고 있어 개발부터 배포까지 모듈단위로 효율적으로 진행할 수 있음
* 하지만 독립적이기 때문에 확장성을 고려한 설계나 트랜잭션 처리가 어렵다는 단점이 있음

</div>
</details>


<details>
<summary><b>TDD란 ?</b></summary>
<div markdown="1">

* 테스트 주도 개발
* 테스트를 먼저 만들고 테스트를 통과하기 위한 것을 구현해 내는 것 
* 즉, 만드는 과정에서 우선 테스트를 작성하고 그걸 통과하는 코드를 만들고를 반복하면서 
* 제대로 동작하는지에 대한 피드백을 적극적으로 받는 것이다.

TDD를 왜 해야할까
* 불확실성이 높을 때 **피드백** 과 **협력** 은 중요하다.
* **피드백** 과 **협력** 은 불확실성이 높을 때 더 좋은 결과를 이끌어낼 수 있다.
* TDD도 마찬가지로 피드백과 협력을 증진시킬 수 있는 요소를 갖추고 있기 때문에 조금 더 확실한 코드를 짤 수 있는것

</div>
</details>


* Todo
    * 디자인 패턴(Front Controller, Singleton, ....)