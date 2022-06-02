# Java 요약

<details>
<summary><b>직렬화 역직렬화란?</b></summary>
<div markdown="1">

* 직렬화와 역직렬화는 자바 시스템 내부에서 사용되는 객체 또는 데이터를 외부의 자바 시스템에서도 사용할 수 있도록 
* 바이트(byte) 형태로 데이터 변환하는 작업을 의미한다.
* 직렬화란 객체를 직렬화하여 전송 가능한 형태로 만드는 것
* 반대로 역직렬화란 데이터를 읽어 객체의 형태로 만드는 것을 의미한다.

</div>
</details>

* Argument Resolver
* Message Converter
* Transactional Runtime Exception 잡는 방법

<details>
<summary><b>Java 8과 11 ?</b></summary>
<div markdown="1">

* 둘다 LTS 버전임
* String 관련 문자열이 좀 더 추가됨
* 람다식의 파라미터에 var 변수를 사용할 수 있음 -> var 변수에 어노테이션을 붙일 수 있음
* 자세하게는 모름...

</div>
</details>


<details>
<summary><b>객체 지향 프로그래밍의 특징</b></summary>
<div markdown="1">

1. 추상화(abstraction)
2. 캡슐화(encapsulation)
3. 상속성(inheritance)
4. 다형성(polymorphism)

</div>
</details>


<details>
<summary><b>SOLID와 다형성</b></summary>
<div markdown="1">

1. SRP : 단일 책임 원칙
2. OCP : 개방-폐쇄 원칙 
    * 확장에는 open , 변경에는 closed
3. LSP : 리스코프 치환 원칙
    * 다형성에서 하위 클래스는 인터페이스 규약을 지켜야 한다
    * ex) 자동차의 엑셀을 뒤로가도록 구현하면 안된다 -> LSP위반
4. ISP : 인터페이스 분리 원칙
    * 범용 인터페이스 하나보다 특정 클라이언트를 위한 인터페이스 여러개가 더 낫다.
    * ex) 자동차인터페이스 -> 운전 인터페이스, 정비 인터페이스로 세분화
5. DIP : 의존관계 역전 원칙
    * 왜 역전일까?
    * 추상화에 의존해야지, 구체화에 의존하면 안된다.
    * 인터페이스와 그것을 구현한 구현클래스가 있다면, 다른 클래스에서는 구현클래스가 아니라 인터페이스에 의존해야 한다.

</div>
</details>


<details>
<summary><b>파라미터와 인자의 차이?</b></summary>
<div markdown="1">

* 매개변수(parameter)는 메소드를 정의할때 사용되는 변수
* 인자(Argument)는 메소드가 호출될때 넘기는 실제 값

</div>
</details>


<details>
<summary><b>(Volatile , Synchronized) 키워드</b></summary>
<div markdown="1">

* volatile keyword는 Java 변수를 Main Memory에 저장하겠다라는 것을 명시하는 것
* 매번 변수의 값을 Read, Write할 때마다 CPU cache가 아닌 Main Memory에서 읽거나 작성하는것
* Multi Thread환경에서 Thread가 변수 값을 읽어올 때 각각의 CPU Cache에 저장된 값이 다르기 때문에 변수 값 불일치 문제가 발생
    ![](https://nesoy.github.io/assets/posts/20180609/2.png)
* volatile 키워드를 추가하게 되면 Main Memory에 저장하고 읽어오기 때문에 변수 값 불일치 문제를 해결할 수 있음
    ~~~java
    public class SharedObject {
        public volatile int counter = 0;
    }
    ~~~
* 언제(When) volatile이 적합?
    * Multi Thread 환경에서 하나의 Thread만 read & write하고 나머지 Thread가 read하는 상황에서 가장 최신의 값을 보장함

<br>

* Java의 synchronized 키워드는 Thread 사이의 동기화 문제를 해결해주는 기법중 하나
* synchronized 키워드는 각 일반 Instance안에 존재하는 Monitor를 이용하여 Thread 사이의 동기화를 수행

</div>
</details>


<details>
<summary><b>JDK, JRE, JVM 관계</b></summary>
<div markdown="1">

* JDK, JRE, JVM
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fc00klf%2FbtqAjMzLyF2%2F6sU1VGp5vqAYIPLsXpakpK%2Fimg.png)
* JDK > JRE > JVM
* JDK = JRE + Development Tools
* JRE = JVM + Library Classes

</div>
</details>


<details>
<summary><b>JVM 이란 ?</b></summary>
<div markdown="1">

* JVM (자바 가상 머신)
* java 코드는 컴파일러를 거쳐 바이트코드(.class)로 변환이 됨
* 바이트코드는 기계어가 아니기 때문에 OS에서 바로 실행될 수 없음
* JVM은 이러한 자바 바이트코드를 OS에 따라 해석해주는 역할을 함
* 자바 프로그램이 어느 기기, 어느 운영체제 상에서도 실행될 수 있게 만들어 주는것임 => WORA(Write once run anyway)
* 자바 프로그램의 메모리를 효율적으로 관리&최적화 해줌

</div>
</details>


<details>
<summary><b>인터프리터 vs 컴파일 언어</b></summary>
<div markdown="1">

* 인터프리터 언어
    * 기계어로 변환하는 과정없이 한줄 한줄 해석하여 바로 명령어를 실행하는 언어
    * R, Python, Ruby와 같은 언어
* 컴파일 언어
    * 소스코드를 모두 기계어로 변환한 후에 JVM 같은 가상 머신에서 기계어 코드를 실행
    * 기계어로 번역하는 빌드 과정에서는 인터프리터 언어에 비해 시간이 소요
    * 하지만 런타임 상황에서는 이미 기계어로 모든 소스코드가 변환되어 있기 때문에 빠르게 실행
* 즉, java는 컴파일 언어이다.

</div>
</details>


<details>
<summary><b>JVM 메모리 구조 </b></summary>
<div markdown="1">

* JVM의 구조는 크게 보면, Garbage Collector, Execution Engine, Class Loader, Runtime Data Area로, 4가지로 나눌 수 있다.
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FpjywN%2FbtqSduBXLIK%2F2QEL5c2nEJXRm0cyhvwxF1%2Fimg.png)

1. Class Loader
~~~
JVM 내로 클래스 파일을 로드하고, 링크를 통해 배치하는 작업을 수행하는 모듈
런타임 시에 동적으로 클래스를 로드합니다.
~~~

2. Execution Engine
~~~
클래스 로더를 통해 JVM 내의 Runtime Data Area에 배치된 바이트 코드들을 명렁어 단위로 읽어서 실행합니다. 
최초 JVM이 나왔을 당시에는 인터프리터 방식이었기때문에 속도가 느리다는 단점이 있었지만 
JIT 컴파일러 방식을 통해 이 점을 보완하였습니다. 
JIT는 바이트 코드를 어셈블러 같은 네이티브 코드로 바꿈으로써 실행이 빠르지만 역시 변환하는데 비용이 발생하였습니다. 
이 같은 이유로 JVM은 모든 코드를 JIT 컴파일러 방식으로 실행하지 않고, 
인터프리터 방식을 사용하다가 일정한 기준이 넘어가면 JIT 컴파일러 방식으로 실행합니다.
~~~
 
3. Garbage Collector
~~~
Garbage Collector(GC)는 힙 메모리 영역에 생성된 객체들 중에서 참조되지 않은 객체들을 탐색 후 제거하는 역할을 합니다. 
이때, GC가 역할을 하는 시간은 언제인지 정확히 알 수 없습니다.
~~~

4. Runtime Data Area
~~~
JVM의 메모리 영역으로 자바 애플리케이션을 실행할 때 사용되는 데이터들을 적재하는 영역입니다. 
이 영역은 크게 Method Area, Heap Area, Stack Area, PC Register, Native Method Stack로 나눌 수 있습니다.
~~~

</div>
</details>


<details>
<summary><b>JVM의 Runtime Data Area</b></summary>
<div markdown="1">

### Runtime Data Area
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FkOOdl%2FbtqR1E0kWdB%2F7El4pzDEIvx0UGXLVanKjK%2Fimg.png)

1. Method area
~~~
모든 쓰레드가 공유하는 메모리 영역입니다. 
메소드 영역은 클래스, 인터페이스, 메소드, 필드, Static 변수 등의 바이트 코드를 보관합니다.
~~~

2. Heap area
~~~
모든 쓰레드가 공유하며, new 키워드로 생성된 객체와 배열이 생성되는 영역입니다. 
또한, 메소드 영역에 로드된 클래스만 생성이 가능하고 
Garbage Collector가 참조되지 않는 메모리를 확인하고 제거하는 영역입니다.
~~~

3. Stack area
~~~
메서드 호출 시마다 각각의 스택 프레임(그 메서드만을 위한 공간)이 생성합니다. 
그리고 메서드 안에서 사용되는 값들을 저장하고, 
호출된 메서드의 매개변수, 지역변수, 리턴 값 및 연산 시 일어나는 값들을 임시로 저장합니다. 
마지막으로, 메서드 수행이 끝나면 프레임별로 삭제합니다.
~~~

4. PC Register
~~~
쓰레드가 시작될 때 생성되며, 생성될 때마다 생성되는 공간으로 쓰레드마다 하나씩 존재합니다. 
쓰레드가 어떤 부분을 무슨 명령으로 실행해야할 지에 대한 기록을 하는 부분으로 
현재 수행중인 JVM 명령의 주소를 갖습니다.
~~~

5. Native method stack
~~~
자바 외 언어로 작성된 네이티브 코드를 위한 메모리 영역입니다.
~~~

</div>
</details>


### 접근 제어자
* private(클래스) -> default(패키지) -> protected(패키지, 상속) -> public 순으로 보다 많은 접근을 허용


<br><br>

### 객체와 인스턴스 차이
* 클래스의 타입으로 선언된 것을 객체
* 메모리에 할당되어 실제로 사용되면 인스턴스
* 객체는 클래스의 인스턴스로 불림

~~~java
public static void main(String[] args) {
    Animal cat, dog; // '객체'

    // 인스턴스화
    cat = new Animal(); // cat은 Animal 클래스의 '인스턴스'(객체를 메모리에 할당)
    dog = new Animal(); // dog은 Animal 클래스의 '인스턴스'(객체를 메모리에 할당)
}
~~~

<br><br>

## 프로그래밍 패러다임
1. 객체지향
2. 절차지향
3. 함수형 프로그래밍 : 순수함수 이용
    * 동일한 입력에는 항상 같은 값을 반환해야 하는 함수
    * 함수의 실행이 프로그램의 실행에 영향을 미치지 않아야 하는 함수
    * 함수 내부에서 인자의 값을 변경하거나 프로그램 상태를 변경하는 Side Effect가 없는 것


<br><br>

## 컴파일 
~~~
컴파일은 인간이 이해할 수 있는 언어로 작성된 소스 코드(고수준 언어 : C, C++, Java 등)를
CPU가 이해할 수 있는 언어(저수준 언어 : 기계어)로 번역(변환)하는 작업
~~~
![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FGb9WO%2FbtrdpL4fvcQ%2Fspc9IYinoZhgHRmJ0l0kjK%2Fimg.png)


<br><br>



## 가비지 컬렉션 Garbage Collection 동작방식
* Java 메모리의 각 영역에서 GC가 발생하면, 사용하지 않는(참조가 존재하지 않는) 객체들은 메모리에서 제거된다.




<br><br>

### wrapper
기본타입(primitive type)을 참조타입(reference type)으로 만드는것을 박싱, 반대를 언박싱 이라고 함



<br><br>

### wrapper 클래스를 사용하는 이유
1. 기본 데이터 타입을 Object로 변환할 수 있다.

2. java.util 패키지의 클래스는 객체만 처리하므로 Wrapper class는 이 경우에도 도움이 된다.

3. ArrayList 등과 같은 Collection Framework의 데이터 구조는 기본 타입이 아닌 객체만 저장하게 되고, Wrapper class를 사용하여 자동박싱/언박싱이 일어난다.

4. 멀티스레딩에서 동기화를 지원하려면 객체가 필요하다.



<br><br>

### 인터페이스와 추상클래스 공통점,차이점
* 공통점 : 상속(extends)받거나, 구현(implements)하는 Class가 Abstract Method를 구현하도록 강제하는 공통점을 가지고 있다.
* 차이점
    * Interface는 부모, 자식 관계인 상속 관계에 얽메이지 않고, 공통 기능이 필요 할때 (다형성과 관련)
    * Abstract Class는 상속 관계에서 부모 Class(여기서는 Abstract Class)를 상속받는 자식 Class들 간에 공통 기능을 각각 구현(상속과 관련)
* 예시
    * 조류라는 Abstract 클래스 하위에 독수리, 오리가 있음
    * Eatable, flightable 이라는 인터페이스가 있음
    * 포유류라는 Abstract클래스 하위에 박쥐가 있음
    * 박쥐클래스는 Eatable, flightable 인터페이스를 상속받을 수 있음



<br><br>

### Checked Exception vs UnChecked Exception
* Checked Exception은 컴파일 단계에서 발생하는 Exception으로 반드시 예외처리를 해야함 (try/catch)
* UnChecked Exception은 런타임 단계에서 발생하는 Exception으로 예외처리를 강제하지 않음 (논리오류 포함)


<br><br>

### static
* 메소드 영역에 저장된다.
* 프로그램의 시작과 동시에 할당되고 프로그램이 종료되어야 메모리에서 소멸된다.


<br><br>

### final
* 필드에 final을 사용하면 해당 필드 변경불가
* 메서드에 final을 사용하면 상속받은 클래스에서 부모의 final 메서드를 재정의 할 수 없음
* final Company company = new Company();
    company = new Company(); //객체를 한번 생성했다면 재생성 불가능
    company.setName("ex회사"); //클래스의 필드는 변경가능
* 클래스에 final을 사용하게되면 그 클래스는 최종상태가 되어 더이상 상속이 불가능



<br><br>

### Stream
* Stream 장단점, 특징
* 중계 오퍼레이션, 종료 오퍼레이션



<br><br>

### Lamda
* 람다식, 익명 클래스, 익명 메소드, 함수형 인터페이스, 메소드 레퍼런스?
* 자바에서 제공하는 함수형 인터페이스?
* Lambda Capturing?


