# Spring Batch

### 스프링배치 개요

<details>
<summary><b>Batch란?, Spring Batch 탄생 배경?</b></summary>
<div markdown="1">

* batch processing 이란?
    * **일괄 처리**를 의미한다.
    * 사용자의 개입없이 실행을 스케줄링할 수 있는 작업(job)의 실행을 의미한다.
    * 프로그램의 Flow에 따라 순차적으로 자료(step)를 처리하는 방식이다.
* spring batch는 왜 생김 ?
    * 자바 기반의 표준 배치 기술이 존재하지 않았음
    * 자바에는 Network, TCP, UDP, Thread 등 개발에 필요한 기본 기술들이 JSP(Java Specification Request)에 명시되어있음
    * 하지만 배치와 관련된 기술은 JSR에 명시되어있지 않았기 때문에, 재사용 가능한 자바 기반 배치 아키텍쳐가 필요했음

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

<br>

### 스프링배치 아키텍처

<details>
<summary><b>Spring Batch 아키텍처</b></summary>
<div markdown="1">

* 업데이트 예정...
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