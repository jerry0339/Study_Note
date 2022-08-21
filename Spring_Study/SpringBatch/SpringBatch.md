# Spring Batch
* 강의내용 정리 - [스프링 배치 - Spring Boot 기반으로 개발하는 Spring Batch](https://www.inflearn.com/course/%EC%8A%A4%ED%94%84%EB%A7%81-%EB%B0%B0%EC%B9%98/)

<br>

## Batch 기본개념

<details>
<summary><b>Batch란?, Spring Batch 탄생 배경?</b></summary>
<div markdown="1">

* batch processing 이란?
    * **일괄 처리**를 의미한다.
    * 사용자의 개입없이 실행을 스케줄링할 수 있는 작업(job)의 실행을 의미한다.
    * 프로그램의 Flow에 따라 순차적으로 자료(step)를 처리하는 방식이다.
* spring batch는 왜 생김 ?
    * 자바 기반의 표준 배치 기술이 존재하지 않았음

</div>
</details>


<details>
<summary><b>Spring Batch 아키텍처</b></summary>
<div markdown="1">

1. Application
    * 개발자가 만든 모든 배치 Job과 커스텀 코드를 포함
    * 개발자는 업무 로직의 구현에만 집중, 공통적인 기반기술은 프레임웍이 담당
2. Batch Core
    * Job을 실행, 모니터링, 관리하는 API로 구성되어 있다.
    * JobLauncher, Job, Step, Flow 등이 속한다.
3. Batch Infrastructure
    * Application, Batch Core 모두 공통 Infrastructure 위에서 빌드한다.
    * Job 실행의 흐름과 처리를 위한 틀을 제공
    * Reader, Processor, Writer, Skip, Retry 등이 속함

</div>
</details>


<details>
<summary><b>Spring Batch 핵심 패턴</b></summary>
<div markdown="1">

* Read : 데이터베이스, 파일, 큐에서 다량의 데이터 조회
* Process : 읽은 데이터를 특정 방법으로 데이터를 가공(변경)
* Write : Process를 거친 데이터를 수정된 양식으로 다시 저장

</div>
</details>


<details>
<summary><b>Spring Batch 시나리오</b></summary>
<div markdown="1">

* 배치 프로세스를 주기적으로 커밋
* 동시 다발적인 Job의 배치 처리, 대용량 병렬 처리
* Job 실패 후 수동 또는 스케줄링에 의한 재시작
* 의존관계가 있는 step 여러 개를 순차적으로 처리
* 조건적 Flow 구성을 통한 체계적이고 유연한 배치 모델 구성
    * 조건적 Flow란 Job의 여러개의 step이 조건적으로 다른 순서의 Flow를 가질 수 있음을 의미
* 반복, 재시도, Skip처리

</div>
</details>


<details>
<summary><b>Spring Batch 아키텍처</b></summary>
<div markdown="1">

1. Application
    * 개발자가 만든 모든 배치 Job과 커스텀 코드를 포함
    * 개발자는 업무 로직의 구현에만 집중, 공통적인 기반기술은 프레임웍이 담당
2. Batch Core
    * Job을 실행, 모니터링, 관리하는 API로 구성되어 있다.
    * JobLauncher, Job, Step, Flow 등이 속한다.
3. Batch Infrastructure
    * Application, Batch Core 모두 공통 Infrastructure 위에서 빌드한다.
    * Job 실행의 흐름과 처리를 위한 틀을 제공
    * Reader, Processor, Writer, Skip, Retry 등이 속함

</div>
</details>



<br><br>

## Spring Batch Job
<details>
<summary><b>Job 이란?</b></summary>
<div markdown="1">

* Job이란 ?
    * 배치 계층 구조에서 가장 상위에 있는 개념으로서 하나의 배치작업 자체를 의미
    * Job Configuration 을 통해 생성되는 객체 단위로서 배치작업을 어떻게 구성하고 실행할 것인지 전체적으로 설정하고 명세해 놓은 객체
    * 배치 Job 을 구성하기 위한 최상위 인터페이스이며 스프링 배치가 기본 구현체를 제공
    * 여러 Step 을 포함하고 있는 컨테이너로서 반드시 한개 이상의 Step으로 구성해야 함
* 구현 방법
    * SimpleJob : 순차적으로 Step을 실행시키는 Job        
    * FlowJob
        * 특정한 조건과 흐름에 따라 Step 을 구성하여 실행시키는 Job
        * Flow 객체를 실행시켜서 작업을 진행

</div>
</details>


<details>
<summary><b>JobInstance 이란?</b></summary>
<div markdown="1">

1. Job Launcher클래스는 Job & JobParameters에 대한 정보를 인자로 받아 Job을 실행시킴
2. Job을 실행시키려면 JobInstance가 필요함
3. 이때, 인자로 받은 Job & JobParameters를 이용하여 JobInstance를 생성하거나 리턴받음 -> Key값을 생성함
    * key값 = Job(이름) + JobParameters(String, Long, Date, Double)
4. 이전에 사용된 적이 있는 Key값이라면 기존의 JobInstance를 리턴받아 사용하고 아니라면 새로운 JobInstance를 생성함
5. 따라서 Job과 JobInstance의 관계는 일대다(1:N)의 관계임

</div>
</details>


<details>
<summary><b>JobParameter 이란?</b></summary>
<div markdown="1">

* Job을 실행할 때 함께 포함되어 사용되는 파라미터를 가진 도메인 객체
* 하나의 Job에 존재할 수 있는 여러개의 JobInstance를 구분하기 위한 용도
* JobParameters와 JobInstance는 1:1 관계
* JobParameters와 JobExecution은 1:M 관계
* 생성 방법(??)
    1. App 실행시 주입
    2. 코드로 생성
    3. SpEL 이용

</div>
</details>


<details>
<summary><b>JobExecution 이란?</b></summary>
<div markdown="1">

* JobInstance가 생성이 되면 JobExecution도 생성이 됨
* Job자체가 성공정으로 완료가 되면 JobExecution에 Completed가 기록됨
* Job실행도중 오류가 생기면 JobExecution에 Failed가 기록됨
* JobExecution에 Completed 기록이 없는 경우(Failed만)에만 해당 JobInstance를 재실행 시킬 수 있음
* Completed가 기록 되었다면, 재실행이 불가함
* 따라서 JobInstance와 JobExecution은 1:N 의 관계임 (Failed면 계속 재샐행가능하고 JobExecution이 쌓임)

</div>
</details>
