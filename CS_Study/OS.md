# OS(Operating System) 요약

<details>
<summary><b>OS란?</b></summary>
<div markdown="1">

* 운영체제(Operating System)는 사용자에게 편리성을 제공하며 컴퓨터의 자원을 효율적으로 관리하는 시스템 소프트웨어
* 프로그램과 하드웨어 사이에서 인터페이스 역할
* 사용자로부터 컴퓨터 자원을 보호하고 할당하는 기능을 수행
* 운영체제의 구조는 크게 사용자 인터페이스와 커널로 나뉨
* 커널이 하드웨어 자원을 보호하기 때문에 사용자는 하드웨어 자원에 직접 접근할 수 없고, 사용자 인터페이스를 통해 접근
* 커널모드에서는 CPU Scheduling(CPU 스케쥴링), Memory Management(메모리 관리), IO Management(입출력 관리), File System Management(파일 시스템 관리) 등의 역할을 수행함

</div>
</details>


<details>
<summary><b>프로세스와 스레드란? 차이점?</b></summary>
<div markdown="1">

* 프로세스는 프로그램이 운영체제에 의해 메모리 공간을 할당받아 실행 중인 것
* 스레드는 프로세스(process) 내에서 실제로 작업을 수행하는 주체 즉, 프로세스 내에서 실행되는 흐름 단위
* 프로세스는 완벽히 독립적이기 때문에 **메모리 영역을 공유하지 않지**만, 쓰레드는 **스택영역을 제외한 메모리 영역을 공유**
* 각각의 스레드는 독립적인 실행흐름을 가지므로 독립적인 함수 호출이 보장되어야 함. 따라서 스레드는 스택영역은 공유x

</div>
</details>


<details>
<summary><b>멀티스레드의 장단점</b></summary>
<div markdown="1">

* stack영역을 제외한 모든 메모리를 공유하기 때문에, 적은 메모리 공간을 차지하고 **Context Switching이 빠르다** = 응답시간이 빠르다.
* 위와 같은 이유로 **자원관리가 효율적**이다.

* 하나의 스레드 장애로 **전체 스레드가 종료**될 위험을 갖고 있다.
* 메모리 영역을 공유하기 때문에 **동기화**가 필요하다.

</div>
</details>


<details>
<summary><b>멀티스레드와 멀티프로세스 차이점</b></summary>
<div markdown="1">

* 멀티 스레드
    * 장점 : 적은 메모리 공간을 차지하고 **Context Switching이 빠르다**
    * 단점 : 동기화 문제와 하나의 스레드 장애로 전체 스레드가 종료 될 위험을 갖고 있음

* 멀티 프로세스
    * 장점 : 하나의 프로세스가 죽더라도 다른 프로세스에 영향을 주지 않아 **안정성이 높음**
    * 단점 : 멀티 스레드보다 **많은 메모리공간**과 CPU 시간을 차지함

</div>
</details>


<details>
<summary><b>PCB란?, Context Switching이란?</b></summary>
<div markdown="1">

* CPU는 한번에 하나의 프로세스(or 쓰레드)만 실행 가능하다.
* CPU에서 여러 실행단위를 돌아가면서 작업을 처리하는 데 이 과정을 **Context Switching**라 한다.

**PCB(Process Control Block)** 란
* 운영체제가 프로세스에 대한 중요한 정보를 저장해 놓을 수 있는 저장 장소이다.
* 프로세스의 ID, 상태(준비, 대기, 실행 등), 레지스터정보, 스케줄링 우선순위등이 저장된다.

**Context Switching** 이란
* CPU가 이전의 프로세스 상태를 PCB에 보관하고, 또 다른 프로세스의 정보를 PCB에서 읽어
* 레지스터에 적재하는 과정을 말한다.

인터럽트가 발생하거나
실행중인 프로세스가 CPU사용을 허가받은 시간(Time Quantum)을 모두 소모하거나
I/O 입출력을 위해 대기해야 하는 경우에
Context Switching이 발생한다.
즉, 프로세스가 준비->실행, 실행->준비, 실행->대기 등으로 **상태가 변경될때** 일어난다.

</div>
</details>


<details>
<summary><b>fork란 prefork, worker ?</b></summary>
<div markdown="1">

* fork()는 현재 프로세스에 대한 자식 프로세스를 생성하는 함수이다.
* 서버가 클라이언트 요청을 받으면 자신이 아니라 fork() 생성된 프로세스로 요청을 처리한다.
* Apache 멀티 프로세스에 관련된 모듈
    * prefork : 한 자식프로세스당 하나의 쓰레드를 사용하는 방법
    * Worker 방식 : 한 자식프로세스당 여러개의 쓰레드를 사용하는 방법

</div>
</details>

<details>
<summary><b>스케줄러란?</b></summary>
<div markdown="1">

* 각 프로세스들의 자원을 할당받는 순서나 일정을 조정해주는 커널의 모듈
* 프로세스들을 스케줄링하기 위해 큐가 존재한다.
    * Job Queue : 프로세스가 처음 들어와서 대기하는 큐
    * Ready Queue : 현재 메모리에 적재되어 실행되기를 기다리는 프로세스를 유지하는 큐
    * Device Queue : Device I/O 작업을 대기하는 큐

</div>
</details>


<details>
<summary><b>스케줄러의 종류?</b></summary>
<div markdown="1">

* 장기, 단기, 중기 스케줄러 3개가 있었지만 가상메모리의 발달로 현재 단기 스케줄러(CPU 스케줄러)만 존재
* 단기 스케줄러 (Short-Term Scheduler) == **CPU 스케줄러**
    * 실제로 CPU가 실행하는 프로세스는 하나이므로 Ready Queue에서 실제로 **실행될 프로세스 하나를 선별**하는 역할을 수행

</div>
</details>


<details>
<summary><b>CPU 스케줄링 알고리즘 목적 ?</b></summary>
<div markdown="1">

* 스케줄링 이란?
    * 디스크에 저장된 애플리케이션을 프로그램이라고 함
    * 메모리에 적재된 프로그램을 프로세스라고 함
    * 프로세스들은 CPU에 의해 실행이 되는데 어떤 프로세스가 실행될지 결정하는것을 스케줄링 이라고 함
* **No starvation** : 각각의 프로세스들이 오랜시간동안 CPU를 할당받지 못하는 상황이 없도록 한다.
* **Fairness** : 각각의 프로세스에 공평하게 CPU를 할당해준다.
* **Balance** : Keeping all parts of the system busy

</div>
</details>


<details>
<summary><b>선점, 비선점 스케줄링</b></summary>
<div markdown="1">

* 이미 할당된 자원을 다른 프로세스가 강탈할수 있는지 없는지에 대해 차이가 있다.
* 비선점 스케줄링(Non-preemptive scheduling) : 프로세스가 작업이 완료될 때까지 CPU를 독점하는 스케줄링 방식
* 선점 스케줄링(Preemptive scheduling) : **높은 우선순위를 가지는 프로세스는 항상 먼저 스케줄되어야 한다.**

</div>
</details>


<details>
<summary><b>동기와 비동기, 블로킹과 논블로킹</b></summary>
<div markdown="1">

* 동기&비동기 : 프로세스의 **수행 순서** 보장에 대한 매커니즘
* 블로킹&논블로킹 : 프로세스의 **유휴 상태**에 대한 매커니즘 (유휴(idle):사용하지 않고 쉬고 있다는 뜻)
* 동기 : 요청과 응답이 **동시에 일어남**. 즉, 요청을 하면 그 결과가 주어져야만 다음 요청이 수행됨
* 비동기 : 요청과 응답이 **동시에 일어나지 않음**
* 블로킹 : 자신의 작업을 진행하다가 다른 주체의 작업이 시작되면 다른 작업이 끝날 때까지 기다렸다가 자신의 작업을 시작하는 것
* 논블로킹 : 다른 주체의 작업에 관련없이 자신의 작업을 하는 것
* [동기&비동기 블로킹&논블로킹 조합 참고링크](https://inpa.tistory.com/entry/%F0%9F%91%A9%E2%80%8D%F0%9F%92%BB-%EB%8F%99%EA%B8%B0%EB%B9%84%EB%8F%99%EA%B8%B0-%EB%B8%94%EB%A1%9C%ED%82%B9%EB%85%BC%EB%B8%94%EB%A1%9C%ED%82%B9-%EA%B0%9C%EB%85%90-%EC%A0%95%EB%A6%AC#thankYou)

</div>
</details>


<details>
<summary><b>spin lock , busy wait ?</b></summary>
<div markdown="1">

스레드가 어떠한 자원을 사용하고 있는 동안 Lock을 걸어 다른 스레드가 임계영역(Critical Section)에 접근하지 못하게 하는데
이때 다른 스레드가 해당 자원에 접근하려고 하면 lock이 풀렸는지 확인하는 작업을 계속하며 기다리는 과정을 거친다.
이러한 과정을 spin lock 또는 busy wait라고 부름

</div>
</details>


<details>
<summary><b>동기화란?</b></summary>
<div markdown="1">

* 동시성 문제 및 가시성 문제를 해결하기 위한 방법
* 여러 스레드가 동시에 같은 인스턴스의 필드의 값을 변경하면서 발생하는 문제를 동시성 문제라고 한다.
* 이 문제를 방지하기 위해 여러 스레드에게 하나의 자원에 대한 처리 권한을 주거나 순서를 조정하여 해결한다.

</div>
</details>


<details>
<summary><b>임계영역과 해결조건</b></summary>
<div markdown="1">

* 임계영역(critical section)
프로세스 간에 동시에 접근하려고 하는 공유자원에서 문제가 발생하지 않도록 (동기화 문제를 해결하기 위해)
한번에 하나의 프로세스만 이용하게끔 공유자원의 독점을 보장하는 코드 영역

1. Mutual Exclusion(상호 배제)
한 프로세스가 공유 자원을 접근하는 임계영역 코드를 수행하고 있으면 
다른 프로세스들은 공유 자원을 접근하는 임계영역 코드를 수행할 수 없다
즉, 하나의 자원에는 하나의 프로세스만 접근 가능하도록 한다.

2. Progress(진행)
임계영역에 어떤 스레드의 접근도 없을때, 항상 접근이 가능해야 한다

3. Bounded Waiting(한정된 대기)
프로세스가 Critical Section 에 진입 신청 후 부터 받아들여질 때가지, 다른 프로세스들이 Critical Section 에 진입하는 횟수는 제한이 있어야 한다
즉, 무한정 대기가 없어야 함

</div>
</details>


<details>
<summary><b>동기화 문제를 해결하는 방법?</b></summary>
<div markdown="1">

임계영역에 lock을 거는 방식으로 동기화문제를 해결할 수 있는데 
lock에 대한 변수 때문에 프로세스가 Critical Section에 들어오고 그 시점에 인터럽트가 발생하여 동시 접근을 허용하는 문제가 발생함
이를 해결하기 위해 **임계영역 해결조건**이 있으며 이 조건을 만족하는 오늘날의 해결책으로
**하드웨어 명령어 (하드웨어 명령어 API)** 를 직접 이용하는 방법과 **세마포어(Semaphore) / 뮤텍스(Mutex) / 모니터(Monitor)** 에서
사용하는 임계영역 접근함수로 하드웨어 명령어를 수행시키는 방법이 있음


</div>
</details>


<details>
<summary><b>세마포어란?</b></summary>
<div markdown="1">

* 세마포어란 깃발이라는 뜻으로 임계영역을 지나가도 되는지 알려주는 역할을 함
* 세마포어는 binary semaphore, counting semaphore 두가지가 있음
* counting semaphore는 "공유자원의 개수를 나타내는 변수"로 쓰임
* binary semaphore는 0또는 1의 값으로 나타냄, lock과 비슷하지만 semaphore는 접근함수 wait(), signal()가 있어 atomic함
* wait(), signal()에서는 하드웨어 명령어를 수행시킴

</div>
</details>


<details>
<summary><b>카운팅 세마포어는 상호배제를 위반하는가?</b></summary>
<div markdown="1">

* 임계구역은 상호 배제를 깨게 되지만, 자원 자체에서는 상호 배제를 유지할 수 있다.
* 예시 : 임계구역(병실)에 1이라는 자원(의자 1개)만 있는데 이 1(의자)을 사용하는 스레드(방문자)가 여러개가 된다는 것이 아니라,
1,2,3,4,5라는 자원(의자 5개)을 5개의 스레드(5명의 방문자)가 사용하게 되는 것이다.


</div>
</details>


<details>
<summary><b>세마포어(Semaphore) / 뮤텍스(Mutex) / 모니터(Monitor) 비교</b></summary>
<div markdown="1">

* 공통점 : 운영체제의 동기화 처리 기법
* (세마포어)와 (뮤텍스,모니터)와의 차이점
    * 뮤텍스, 모니터는 상호배제를 함으로써 **임계구역에 하나의 스레드**만 들어갈 수 있음 (binary semaphore와 유사)
    * 세마포어는 하나의 스레드만 들어가게 할 수도 있고(binary) 여러개의 스레드가 들어갈 수도 있다(counting)
* (세마포어)와 (뮤텍스)의 차이점
    * 뮤텍스는 스레드 에서 Lock을 가지고 있다.
    * 뮤텍스를 소유하고있는 스레드만 해당 뮤텍스를 해제할 수 있다. 하지만, 세마포어는 소유하지 않고 있는 스레드가 세마포어를 해제할 수 있다.
    * 세마포어는 소유할 수 없으며, 뮤텍스는 소유할 수 있고 소유주가 그에 대한 책임을 가지기 때문이다.
    * 즉, 세마포어는 뮤텍스가 될 수 있지만 뮤텍스는 세마포어가 될 수 없다.
    * 세마포어는 동기화 대상이 여러개 일 때, 뮤텍스는 동기화 대상이 오로지 하나 일 때 사용한다.
* (뮤텍스)와 (모니터)의 차이점
    * 뮤텍스는 **다른 프로세스간**의 동기화 처리
    * 모니터는 **하나의 프로세스내**의 스레드간의 동기화 처리
    * 따라서 뮤텍스는 무겁고(heavy-weight) 느리며(slower) 모니터는 가볍고(light-weight) 빠르다(faster).
* (세마포어)와 (모니터)의 차이점
    * 모니터는 공유자원에 접근하기 위한 키 획득과 자원 사용 후 해제를 모두 처리해 주어서 간단하다. (예시- java의 synchronized)
    * 세마포어는 **직접 키 해제와 공유자원 접근 처리**가 필요하다
    * Java와 같은 고급언어에서 모니터를 기본적으로 제공, C는 사용불가
* [참고링크](https://dev-splin.github.io/cs(computer%20science)/operating%20system/OS-Mutex,Semaphore,Monitor/)

</div>
</details>


<details>
<summary><b>User mode, Kernel mode? 목적 ?</b></summary>
<div markdown="1">

* 유저모드(1) 커널모드(0)는 모드비트로 구분
* UserMode는 사용자가 응용프로그램들을 사용할때 접근할 수 있는 영역이다.
* KernelMode는 인터럽트나 System-call이 걸리는 경우 운영체제를 통해서 호출되는 영역으로 모든 메모리에 접근가능
* KernelMode는 CPU Scheduling(CPU 스케쥴링), Memory Management(메모리 관리), IO Management(입출력 관리), File System Management(파일 시스템 관리)등의 작업을 수행하며 외부로부터 System data(I/O장치 같은)및 CPU메모리와 같은 중요 자원으로의 접근을 막아준다.

</div>
</details>


<details>
<summary><b>인터럽트란?</b></summary>
<div markdown="1">

인터럽트란 cpu가 프로세스를 실행하고 있을 때 입출력, 파일읽기, 예외사항 등이 발생하여 처리가 필요한 경우 cpu에 알려주는것

</div>
</details>


<details>
<summary><b>인터럽트 종류, 우선순위</b></summary>
<div markdown="1">

* 외부 인터럽트 : 하드웨어에 의해 생기는 인터럽트, CPU가 아닌 다른 하드웨어 장치가 발생시키거나 CPU의 기능에 오류 발생시 생김
* 내부 인터럽트 : Exception인터럽트 또는 Trap이라고 불리며 잘못된 명령이나 데이터사용 또는 System-call이 발생시 생김
* 소프트웨어 인터럽트(SVC: SuperVisor Call) : 프로그램실행 또는 Supervisor를 호출, 다른 프로세스 실행시 생김
* 하드웨어(외부) 인터럽트가 소프트웨어,내부 인터럽트보다 우선순위가 높다.

</div>
</details>


<details>
<summary><b>인터럽트 과정</b></summary>
<div markdown="1">

* 용어
    * PC(Program counter) : 다음에 실행될 명령어의 주소, 명령어 포인터라고도 불림
    * 인터럽트 벡터 : 인터럽트 발생시 인터럽트 핸들러의 주소를 보관
    * 인터럽트 핸들러 : ISR(Interrupt Service Routine) 예시 -> 키보드 입력시 키보드 인터럽트 핸들러가 호출됨
* 과정
    1. 인터럽트 발생시 프로세스 중단
    2. 현재 프로세스의 상태 보존 (Context Switching 시작)
    3. 인터럽트 처리 루틴 실행(인터럽트 벡터를 읽고 인터럽트 핸들러의 주소값을 읽어옴)
    4. 인터럽트 서비스 루틴 실행(= 인터럽트 핸들러)
    5. 이전에 인터럽트 요청 신호가 발생했을 때, 보관한 PC(Program counter)값을 복원
    6. 인터럽트 발생 이전에 수행중이던 프로그램을 계속 실행

</div>
</details>


<details>
<summary><b>데드락(Deadlock)이란?</b></summary>
<div markdown="1">

* 데드락(교착상태)이란 둘 이상의 프로세스가 다른 프로세스가 점유하고 있는 자원을 서로 기다릴 때를 나타냄 (= 무한대기)
* 운영체제에서 대부분의 교착상태는 세마포어를 차지하려는 경쟁에서 발생

</div>
</details>


<details>
<summary><b>데드락이 생기는 과정 예시</b></summary>
<div markdown="1">

1. 프로세스 P0이 A자원에 세마포어를 가진 상태에서 **인터럽트**가 걸린다.
2. P1으로 Context Switching이 되고 P0는 대기상태로 바뀐다.
3. P1이 자원B에 세마포어를 걸어 공유자원B를 확보
4. P1이 A를 확보하려고 하지만 P0이 사용중이라 대기상태로 바뀐다.
5. P0으로 Context Switching이 다시 되고 B를 확보하려고 하지만 P1이 사용중이니 대기상태로 바뀐다.
6. P0과 P1이 서로가 가지고 있는 자원을 기다리게 되는 **교착상태**에 빠지게 된다.

</div>
</details>


<details>
<summary><b>데드락의 발생조건</b></summary>
<div markdown="1">

1. 상호 배제 (Mutual Exclusion)
동기화를 만족시키기 위한 조건과 같다. 
하나의 프로세스가 자원을 사용할 경우 다른 프로세스는 그 자원을 사용할 수 없는 것을 의미

2. 점유와 대기 (Hold and wait)
프로세스가 이미 어떤 자원을 점유하고 있으면서 다른 종류의 자원을 요구하는 것을 의미

3. 비선점 (No preemption)
임의의 프로세스가 자원을 할당 받은 상태에서 다른 프로세스가 이 자원을 뺏어서 사용할 수 없는 형태를 의미

4. 환형대기 (circle wait)
프로세스와 자원들이 원형을 이루며, 
각 프로세스는 자신에게 할당된 자원을 가지면서 상대방 프로세스의 자원을 상호 요청하는 경우를 의미

</div>
</details>


<details>
<summary><b>데드락 해결방법</b></summary>
<div markdown="1">

1. 예방 (prevention)
위의 데드락 발생조건 4가지 중 하나라도 발생하지 않도록 사전에 예방

2. 회피 (avoidance)
데드락이 빠질 가능성이 있는지 없는지 운영체제가 검사하고 괜찮은 경우만 자원을 할당하여 데드락을 회피
ex) 은행원 알고리즘

3. 탐지 (Detection)
교착상태 발생을 허용하고 발생시 원인을 규명하여 해결
ex) 자원할당 그래프

4. 회복 (recovery)
교착상태 프로세스들을 모두 중지 또는 교착상태가 해결될 때까지 프로세스 하나씩 중지(환형대기 배제)

5. 무시 (Do Nothing, ignore)
운영체제가 교착상태를 무시함. 개발자가 데드락에 빠질 가능성이 없도록 프로그램을 설계해야 함

</div>
</details>


<details>
<summary><b>메모리 관리의 배경,목적</b></summary>
<div markdown="1">

* 프로그램의 실행(프로세스)를 위해서는 메모리를 할당해야 함
* 논리적 주소 & 물리적 주소 차이
    * 물리적 주소 는 메모리 장치의 실제 위치를 ​​참조
    * 논리적 주소는 프로그램 수행중 CPU가 생성하는 가상 주소
* 메모리 관리 목적
    1. **제한된 물리 메모리의 효율적인 사용**이 목적 - 여러 프로세스에게 효율적으로 할당
    2. 효율적인 메모리 참조 (논리 -> 물리 주소 변환)

</div>
</details>


<details>
<summary><b>가상 메모리란?</b></summary>
<div markdown="1">

* 가상메모리 탄생 배경
    * 이전에는 코드의 전부를 물리 메모리에 존재시켜야 했고, 메모리 용량보다 큰 프로그램은 실행시킬 수 없었다.
    * 여러 프로그램을 동시에 메모리에 올리기에는 용량의 한계와, 페이지 교체등의 성능 이슈가 발생함
    * 가끔만 사용되는 코드가 메모리를 차지하고 프로그램이 실행되려면 프로세스 전체가 불필요하게 메모리에 올라와 있어야 함
* 가상메모리란 프로세스 전체가 메모리 내에 올라오지 않더라도 실행이 가능하도록 하는 기법
    * 논리 메모리의 가상 주소를 사용하면서 물리 메모리 크기에 제약받지 않게 됨
    * 더 많은 프로그램을 동시에 실행할 수 있게 됨
    * 이에 따라 **응답시간은 유지**되고, **CPU 이용률과 처리율은 높아짐**

</div>
</details>


<details>
<summary><b>MMU란 ?, Contiguous Allocation 이란?</b></summary>
<div markdown="1">

* **MMU**는 CPU코어 안에 탑재되어 가상 주소(Logical Memory)를 실제 메모리(Physical Memory) 주소로 변환해주는 Hardware device이다.
* CPU에 탑재된 가상 주소가 **연속적으로 할당** 되어 있으면 MMU를 통해 변환되는 물리적 주소도 연속적으로 배치된다. (**Contiguous Allocation**)

</div>
</details>


<details>
<summary><b>Page와 Frame</b></summary>
<div markdown="1">

* Logical address space를 동일한 크기로 나눈것을 **페이지(Page)** 라고 함
* Physical memory를 나눈것을 **프레임(Frame)** 이라고 함

</div>
</details>


<details>
<summary><b>스와핑(Swapping) 이란?</b></summary>
<div markdown="1">

* 주기억장치에 적재한 하나의 프로세스와 보조기억장치에 적재한 다른 프로세스의 메모리를 교체하는 기법
* CPU에서 실행되지 않는 프로세스 중 일부를 메모리가 아닌 디스크에 저장하는 기법이다.
* swap in : 디스크 → 메모리
* swap out : 메모리 → 디스크
* 가상 메모리 기법의 핵심으로 디스크를 활용하여 큰 메모리가 있는 것처럼 효율적으로 사용할 수 있는 기법
* 예시 : 유저공간에서 10개의 프로세스만 수용가능한데 하나의 프로세스가 더 들어와야 한다면 오랫동안 실행되지 않은 프로세스를 swap out시키고 해당 프로세스에 대한 요청이 다시 생기면 swap in으로 메모리에 적재함
* Context Switching 비용이 큰 단점이 있음

![](https://zitoc.com/wp-content/uploads/2019/02/Swapping.png)

</div>
</details>


<details>
<summary><b>스와핑과 VMM(Virtual Memory Management)의 차이?</b></summary>
<div markdown="1">

* Swapping은 **프로세스 단위**로 Swap in , Swap out을 하지만 VMM은 **Paging 단위**로 Swap함

</div>
</details>


<details>
<summary><b>단편화란 ? (외부, 내부 단편화)</b></summary>
<div markdown="1">

* **단편화**는 프로세스가 메모리에 올라오고 내려가면서 발생하는 **메모리 낭비 현상**이며, 내부 단편화와 외부 단편화가 있음.
* 연속적 할당을 통해 프로세스가 메모리에 연속적으로 배치되는데, 이때 어떤 프로세스가 종료되어 Swap out이 수행됐을때 메모리에 hole이 생김
* 다음으로 메모리에 적재되어야 할 프로세스가 hole보다 작은 크기인 경우 또 다른 hole이 생김
* 메모리의 총 공간을 계산했을때 요청을 만족할만한 충분한 메모리가 있음에도 여러 작은 크기의 hole로 인해 프로세스가 수행되지 못함.
* 위와 같은 메모리의 단편화 현상을 **외부 단편화** 라고함
* 외부 단편화 해결책
    * first fit : 가장 최초로 발견되는 구멍에 할당
    * best fit : 외부 단편화가 가장 작게 발생하는 구멍에 할당
    * worst fit : 가장 큰 구멍에 할당
* 위의 해결책은 외부 단편화의 근본적인 해결책이 되진 않는다.

<br>

* **내부 단편화**는 분할된 메모리의 크기보다 프로세스의 크기가 작아서 발생하는 메모리 낭비 현상이다. 
* 논리주소(Logical address)를 동일한 크기로 나눈 것 즉, 페이지에 의해 생기는 단편화 현상임. 
* 외부단편화가 절대 발생하지 않음(페이지로 관리하기 때문)
* 프로세스를 페이지에 적재하기 위해 분할하면서 Page 크기에 딱 맞게 분할되지 않을 수 있는 것임

</div>
</details>


<details>
<summary><b>세그멘테이션(Segmentation) 이란?</b></summary>
<div markdown="1">

* [출처](https://steady-coding.tistory.com/524)
* 세그먼트는 가상 메모리를 서로 크기가 다른 논리적 단위로 분할한 것을 의미함
* 세그멘테이션은 프로세스를 물리적 단위인 페이지가 아닌 논리적 단위인 세그먼트로 분할해서 메모리에 적재하는 방식이다.
* 돼지를 도축할 때, 페이징은 돼지를 같은 크기로 잘라서 보관하는 것이라면 세그멘테이션은 부위 별로 잘라서 보관한다고 이해하면 됨
* 세그먼트는 의미가 같지 않는 논리적 내용을 기준으로 프로그램을 분할하기 때문에 크기가 같지 않다.
* 장점
    * 내부 단편화 문제가 해소된다.
    * 보호와 공유 기능을 수행할 수 있음 
    * 프로그램의 중요한 부분과 중요하지 않은 부분을 분리하여 저장할 수 있음
    * 같은 코드 영역은 한 번에 저장할 수 있다.
* 단점
    * 외부 단편화 문제가 생길 수 있다.

</div>
</details>


<details>
<summary><b>페이지 교체란?, 페이지 교체 알고리즘</b></summary>
<div markdown="1">

* **요구페이징**
    * 프로그램 전체를 Swap in(디스크->메모리) 하는 대신, 초기에 필요한 것들만 페이지들만 적재하는 전략을 요구 페이징 이라고 함
* **페이지 교체**
    ~~~
    요구 페이징 에서 언급된대로 프로그램 실행시에 모든 항목이 물리 메모리에 올라오지 않기 때문에, 
    프로세스의 동작에 필요한 페이지를 요청하는 과정에서 page fault(페이지 부재)가 발생하게 되면, 
    원하는 페이지를 보조저장장치에서 가져오게 된다. 
    하지만, 만약 물리 메모리가 모두 사용중인 상황이라면, 페이지 교체가 이뤄져야 한다.
    ~~~
* 페이지 교체 알고리즘 종류
    * OPT - Optimal : 앞으로 가장 오랫동안 사용되지 않을 페이지 교체
    * FIFO - First In First Out
    * LRU - Least Recently Used : 가장 오랫동안 사용되지 않은 페이지 교체
    * LFU - Least Frequently Used : 참조 횟수가 가장 작은 페이지 교체
    * MFU - Most Frequently used : 참조 횟수가 가장 많은 페이지 교체
    * NUR - Not Used Recently : 최근에 사용하지 않은 페이지 교체

</div>
</details>


<details>
<summary><b>운영체제에서 캐시란?</b></summary>
<div markdown="1">

* 주기억장치에서 자주 사용하는 프로그램과 데이터를 저장해두어 속도를 빠르게 하는 메모리
* 속도가 빠른 장치와 느린 장치간의 **속도 차에 따른 병목현상**을 줄이기 위한 범용 메모리
* 주기억장치와 CPU사이에 위치, CPU의 속도와 비슷할 정도의 속도를 가짐(CPU가 제일 빠름)
* 캐시메모리를 사용하면 **주기억장치를 접근하는 횟수가 줄어**들어 **컴퓨터의 처리속도가 향상**된다

</div>
</details>


<details>
<summary><b>캐시의 지역성이란?</b></summary>
<div markdown="1">

* 캐시가 효율적으로 동작하려면, 캐시의 적중율(Hit-rate)를 극대화 시켜야 한다.
* 지역성이란, 데이터 접근이 시간적, 혹은 공간적으로 가깝게 일어나는 것을 의미한다.
* 지역성의 전제 조건으로 프로그램은 모든 코드나 데이터를 균등하게 Access하지 않는다는 특성을 기본으로 한다.
* 즉, 지역성(Locality)이란 기억장치 내의 정보를 균일하게 Access하는 것이 아닌 어느 한 순간에 특정 부분을 집중적으로 참조하는 특성이다.
* 지역성의 종류
    1. 시간 지역성 : 최근에 참조된 주소의 내용은 곧 다음에 다시 참조되는 특성.
    2. 공간 지역성 : 대부분의 실제 프로그램이 참조된 주소와 인접한 주소의 내용이 다시 참조되는 특성

</div>
</details>

* Todo
    * 동시성, 병렬성