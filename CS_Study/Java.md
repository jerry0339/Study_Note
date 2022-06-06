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


<details>
<summary><b>Java 8과 11 ? (수정중)</b></summary>
<div markdown="1">

* 둘다 LTS 버전임
* Java 8
    * Metaspace란 ?
        * JDK 8부터 Heap영역의 Permanent Generation 영역이 제거되었다.
        * 대신 Native Memory 영역에 Metaspace 영역이 추가되었다.
        * Perm은 JVM에 의해 크기가 강제되던 영역이다.
        * Metaspace는 Native memory 영역으로, OS가 자동으로 크기를 조절한다.
        * 옵션으로 Metaspace의 크기를 줄일 수도 있다.
        * 그 결과 기존과 비교해 큰 메모리 영역을 사용할 수 있게 되었다.
        * Perm 영역 크기로 인한 java.lang.OutOfMemoryError(`OOM`)은 더이상 마주칠 일이 없어짐

* Java 11
    * String 관련 문자열이 좀 더 추가됨
    * 람다식의 파라미터에 var 변수를 사용할 수 있음 -> var 변수에 어노테이션을 붙일 수 있음

</div>
</details>


<details>
<summary><b>객체 지향 프로그래밍의 특징</b></summary>
<div markdown="1">

1. 추상화(abstraction)
2. 캡슐화(encapsulation)
3. 상속성(inheritance)
4. 다형성(polymorphism) : 여러 형태를 받아들일 수 있는 성질

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
<summary><b>객체와 인스턴스 차이</b></summary>
<div markdown="1">

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

* Java의 synchronized 키워드는 Thread 사이의 동기화 문제를 해결해주는 기법중 하나
* synchronized 키워드는 각 일반 Instance안에 존재하는 Monitor를 이용하여 Thread 사이의 동기화를 수행
* synchronized는 특정 Thead가 해당 블럭 전체를 lock하기 때문에 자원 낭비가 심함
* NonBlocking하면서 동기화 문제를 해결하기 위한 방법으로 Atomic이 있음.

<br>

* 멀티쓰레드환경, 멀티코어 환경에서는 각 CPU는 메인 메모리에서 변수값을 참조하는게 아니라 각 CPU의 캐시 영역에서 메모리를 참조
* volatile keyword는 Java 변수를 Main Memory에 저장하겠다라는 것을 명시하는 것
* 매번 변수의 값을 Read, Write할 때마다 CPU cache가 아닌 Main Memory에서 읽거나 작성하는것
* Multi Thread환경에서 Thread가 변수 값을 읽어올 때 각각의 CPU Cache에 저장된 값이 다르기 때문에 변수 값 불일치 문제가 발생하기 때문
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

* NonBlocking하면서 동기화 문제를 해결하기 위한 방법이 Atomic.
* Atomic의 동작 핵심원리는 바로 CAS알고리즘
* Volatile 에서 설명했듯이, 메인메모리에 저장된 값과 CPU캐시에 저장된 값이 다른 경우가 있을 수 있음 (가시성문제)
* 이럴때 사용하는 것이 **CAS알고리즘**임
    * 현재 쓰레드에 저장된 값과 메인메모리에 저장된 값을 비교
    * 일치하는경우 새로운 값으로 교체되고 , 일치하지않는다면 실패하고 재시도

<br>

* Volatile 키워드가 있는데 Atomic 키워드를 사용하는 이유 ?
    * volatile 키워드는 오직 한개의 쓰레드에서 쓰기작업을할때, 그리고 다른 쓰레드는 읽기작업만을 할때 안정성을 보장
    * 하지만 AtomicInteger는 여러 쓰레드에서 읽기/쓰기작업을 병행할 수 있음.
    * 그래서 CAS 알고리즘을 사용하여 2중 안전을 기하는 방법을 사용하는 것임

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
<summary><b>컴파일 이란?</b></summary>
<div markdown="1">

~~~
컴파일은 인간이 이해할 수 있는 언어로 작성된 소스 코드(고수준 언어 : C, C++, Java 등)를
CPU가 이해할 수 있는 언어(저수준 언어 : 기계어)로 번역(변환)하는 작업
~~~

![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FGb9WO%2FbtrdpL4fvcQ%2Fspc9IYinoZhgHRmJ0l0kjK%2Fimg.png)

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
* java는 컴파일 언어이다.

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

* 메타 데이터란? 
    * 클래스의 이름, 생성자 정보, 필드 정보, 메소드 정보, bytecode, exception table, Annotation 등
    * JVM이 해당 class에 대해서 알아야 하는 모든 정보
* Runtime Constant Pool 영역이란 ?
    * 클래스/인터페이스의 메소드, 필드, 문자열 상수등의 레퍼런스(가상주소) 가 저장됨
    * 이들의 물리적인 메모리 위치를 참조할 경우에 사용

</div>
</details>


<details>
<summary><b>JVM 메모리 구조 (Java7, Java8 비교) </b></summary>
<div markdown="1">

* 전체적인 JVM 메모리 구조와 동작방식에 대한 그림
    ![](https://velog.velcdn.com/images/hosunghan0821/post/aea3b9ab-e226-4744-833d-da1f41b2dbf2/image.png)

* JVM의 Runtime Data Area 메모리 구조(`Java 7`)
    * Java 7에서의 Runtime Data Area는 크게 **Heap, PermGen, Native Memory** 3가지 영역이 존재한다.
    * **PermGen(Permanent Generation)영역**은 위 그림의 **Method 영역**에 해당한다.
    * 위 그림의 Stack, PC Resister, Native Method Stack 영역은 **Native Memory 영역** 해당한다.
    * 위의 내용(Java 7)에 대한 자세한 메모리 구조는 아래의 그림에서 확인할 수 있다.
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FIg9mc%2FbtrAxkQGskP%2FbRhmyeWLZAfqo25b17QRC1%2Fimg.png)

* Java 8 부터는 PermGen영역이 Metaspace로 완전히 대체되었다.
    * Java 8 부터는 Java 7의 PermGen(Method 영역)이 Metaspace로 대체되었으며 Native Memory영역에 속한다.
    * PermGen 영역은 JVM에 의해 크기가 강제되던 영역이다.
    * PermGen 영역 크기로 인해 java.lang.OutOfMemoryError(`OOM`)가 발생한다는 단점이 있었음
    * Java8부터는 PermGen의 메모리 할당방식을 바꾸어 Metaspace이라는 영역으로 대체했다. 
    * Metaspace는 Native memory 영역으로, OS가 자동으로 크기를 조절하여 공간을 확보한다.
    * 따라서 OOM 발생확률을 줄일 수 있었다. Java 8에서 바뀐 Memory 구조는 아래와 같다.
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcQbwRJ%2FbtrAzvcY2AP%2FAruhfLyp48u0JktHxhUnzK%2Fimg.png)

* Java7, Java8 의 간단한 JVM 메모리 구조
    * C Heap = Native Stack(=Native Method Stack)
    * Thread Stack = Stack 영역
    * Java 7의 JVM
    ![](https://becomeweasel.me/static/51f2865401bf42f831eebc6e076cd1cf/6c2f2/jvm7.png)
    * Java 8의 JVM
    ![](https://becomeweasel.me/static/bb5245914008655bff34d9e7e26c4ef6/c8e86/jvm8.png)

</div>
</details>


<details>
<summary><b>JVM의 Runtime Data Area 자세한 설명</b></summary>
<div markdown="1">

* Java7의 JVM 구조
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FIg9mc%2FbtrAxkQGskP%2FbRhmyeWLZAfqo25b17QRC1%2Fimg.png)

* Java8의 JVM 구조
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FcQbwRJ%2FbtrAzvcY2AP%2FAruhfLyp48u0JktHxhUnzK%2Fimg.png)

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


<details>
<summary><b>GC(가비지 컬렉션, Garbage Collection) 이란?</b></summary>
<div markdown="1">

* [참고1](https://llnote.tistory.com/709), [참고2](https://d2.naver.com/helloworld/1329), [참고3](https://mirinae312.github.io/develop/2018/06/04/jvm_gc.html)
* stop-the-world란, GC을 실행하기 위해 JVM이 애플리케이션 실행을 멈추는 것
* stop-the-world가 발생하면 GC를 실행하는 쓰레드를 제외한 나머지 쓰레드는 모두 작업을 멈추고 GC작업 완료후 다시 시작
* 가비지 컬렉터의 전제조건
    * 대부분의 객체는 금방 접근 불가능 상태(unreachable)가 된다.
    * 오래된 객체에서 젊은 객체로의 참조는 아주 적게 존재한다.

</div>
</details>


<details>
<summary><b>Wrapper 클래스란?, 사용하는 이유 ?</b></summary>
<div markdown="1">

* 기본 타입의 데이터를 객체로 바꿀필요가 있을때 Wrapper 클래스를 사용
* 기본타입(primitive type)을 참조타입(reference type)으로 만드는것을 박싱, 반대를 언박싱 이라고 함
* 사용하는 이유
    1. 기본 데이터 타입을 Object로 변환할 수 있다.
    2. java.util 패키지의 클래스는 객체만 처리하므로 Wrapper class는 이 경우에도 도움이 된다.
    3. ArrayList 등과 같은 Collection Framework의 데이터 구조는 기본 타입이 아닌 객체만 저장하게 되고, Wrapper class를 사용하여 자동박싱/언박싱이 일어난다.
    4. 멀티스레딩에서 동기화를 지원하려면 객체가 필요하다.

</div>
</details>


<details>
<summary><b>인터페이스와 추상클래스 공통점,차이점</b></summary>
<div markdown="1">

* 공통점 : 상속(extends)받거나, 구현(implements)하는 Class가 Abstract Method를 구현하도록 강제하는 공통점을 가지고 있다.
* 차이점
    * Interface는 부모, 자식 관계인 상속 관계에 얽메이지 않고, 공통 기능이 필요 할때 (다형성과 관련)
    * Abstract Class는 상속 관계에서 부모 Class(여기서는 Abstract Class)를 상속받는 자식 Class들 간에 공통 기능을 각각 구현(상속과 관련)

</div>
</details>


<details>
<summary><b>Checked Exception vs Unchecked Exception</b></summary>
<div markdown="1">

* Checked Exception은 컴파일 단계에서 발생하는 Exception으로 반드시 예외처리를 해야함 (try/catch)
* UnChecked Exception은 런타임 단계에서 발생하는 Exception으로 예외처리를 강제하지 않음 (논리오류 포함)

</div>
</details>


<details>
<summary><b>POJO란 ?</b></summary>
<div markdown="1">

* POJO(Plain Old Java Object) 란?
* 객체지향적인 원리에 충실하면서, 환경과 기술에 종속되지 않고 필요에 따라 재활용될 수 있는 방식으로 설계된 오브젝트

</div>
</details>


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
