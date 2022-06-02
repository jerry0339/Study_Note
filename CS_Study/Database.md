# Database 요약

<details>
<summary><b>DB, DBMS ?</b></summary>
<div markdown="1">

* DB란 여러 사람에 의해 공유되어 사용될 목적으로 통합하여 관리되는 **데이터의 집합**
* DBMS란 Database Management System의 약자로 말 그대로 DB를 관리하며 응용 프로그램들이 DB를 공유하며 사용할 수 있는 환경을 제공한다.
* 즉, DB와 응용 프로그램 사이를 중계하는 역할을 한다.
* 응용프로그램들은 DB를 직접 조작하지 않고 DBMS를 통해 조작하고 관리할 수 있는 것

</div>
</details>


<details>
<summary><b>데이터베이스란?, 왜 사용함?</b></summary>
<div markdown="1">

* DB란 여러 사람에 의해 공유되어 사용될 목적으로 통합하여 관리되는 데이터의 집합
* 데이터베이스가 존재하기 이전에는 데이터를 관리(CRUD등)하기 위해서 프로그램 내에 관리하기 위한 코드가 포함되어야 했다.
* 따라서 데이터를 관리하기 위해서는 프로그램 내에 작성된 코드에 크게 의존할 수 밖에 없었다.
* 이렇게 DB를 사용하지 않으면 '데이터 종속성'에 대한 이슈 뿐만 아니라 '데이터 중복성', 보안문제 등 여러 문제가 발생할 수 있다.
* 이러한 문제들을 DB를 사용하면 해결할 수 있다.
    * 데이터의 중복성 최소화
    * 데이터의 일관성 및 무결성 유지
    * 데이터의 보안 (승인받지 않은 요청으로 부터 데이터를 보호)

</div>
</details>

<details>
<summary><b>데이터의 정합성, 일관성, 무결성이란 ?</b></summary>
<div markdown="1">

* 데이터 정합성은 데이터가 서로 모순 없이 일관되게 일치해야 함을 나타낸다.
* 데이터의 일관성은 동일한 데이터가 여러 파일들로 존재하게 되었을 때, 그 내용은 모두 일관되게 동일하여야 한다는 것을 나타냄
    * 데이터가 중복으로 존재할 경우 일관성을 지키기 어려움
* 데이터 무결성은 데이터의 정확성, 일관성이 유지되는 것을 의미 (정확성-> 중복or데이터 누락이 없는 상태)
    * 개체 무결성 : 기본키는 Null값이나 중복된 값을 가질 수 없음
    * 참조 무결성 (외래키 제약) : 외래키는 Null 이거나 참조하는 릴레이션의 기본키 값과 동일해야 함
    * [등등...](https://iingang.github.io/posts/DB-Integrity-constraint/)

</div>
</details>


<details>
<summary><b>Sharding 이란?</b></summary>
<div markdown="1">

* [참고링크](https://techblog.woowahan.com/2687/)
* 같은 타입(테이블)의 데이터를 다수의 데이터베이스에 쪼개서 저장하는 것
* 하나의 DB에 데이터가 늘어나면 용량 이슈, CRUD 성능저하 이슈 -> 샤딩을 통해 DB트래픽 분산
* DB를 분산(샤딩)하면 특정 DB의 장애가 전면장애로 이어지지 않는다는 장점이 있음
* 데이터를 분산하고, 해당 데이터의 위치를 찾기 위해서는 라우팅이 잘 이루어져야 하는데 이때 유일한 키값(PK | 샤딩키)을 필요로 함
* 라우팅방법은 모듈러(Modular) 샤딩, 레인지(Range) 샤딩 2가지가 있음
* Modular sharding -> (PK % DB수)
    * 장점 : 레인지 샤딩에 비해 데이터가 균일하게 분산됨 
    * 단점 : DB를 추가 증설하면 모듈러값이 달라지게 되어 이미 적재된 데이터의 재정렬이 필요하다. 
* Range sharding -> (1~4는 DB1, 5~9는 DB2,, 이런식)
    * 장점 : 모듈러샤딩에 비해 기본적으로 증설에 재정렬 비용이 들지 않는다.
    * 단점 : 일부 DB에 데이터가 몰릴 수 있다. -> 한쪽 데이터가 몰리거나 너무 트래픽이 없는 경우 자원낭비 -> 특정DB 확장or축소로 해결

</div>
</details>


<details>
<summary><b>Index 란?</b></summary>
<div markdown="1">

* 추가적인 저장공간을 활용하여 데이터베이스 테이블에 대한 검색(Select)속도를 향상시키기 위한 자료구조
* Index를 사용하면 Select외에도 Update & Delete의 성능도 함께 향상된다. 그 이유는 Update & Delete를 하려면 대상을 조회해야 하기 때문
* 하지만 역효과를 주의해야 한다.
* 값을 빠르게 탐색하기 위해 Index를 항상 정렬된 상태로 유지해야 하는데 이때 Insert, Delete, Update에 다음과 같은 연산이 추가된다.
    * Insert : 새로운 데이터에 대한 인덱스 추가
    * Delete : 삭제하는 데이터의 인덱스를 사용하지 않는다는 작업을 진행
    * Update : 기존의 인덱스를 사용하지 않음 처리하고, 갱신된 데이터에 대해 인덱스를 추가함
* 즉, Insert/Create, Delete, Update가 빈번한 속성에 Index를 걸면 인덱스의 크기가 비대해져서 성능이 오히려 저하되는 역효과가 발생
* 장점 : 테이블을 조회하는 속도 향상 -> 시스템 부하 줄임
* 단점
    * 인덱스를 관리하기 위해 DB의 약 10%에 해당하는 저장공간이 필요하다.
    * 인덱스를 관리하기 위해 추가 작업이 필요하다.
    * 인덱스를 잘못 사용할 경우 오히려 성능이 저하되는 역효과가 발생할 수 있다.

</div>
</details>


<details>
<summary><b>Index를 사용하는 이유, 사용하면 좋은 경우 ?</b></summary>
<div markdown="1">

* **인덱스를 사용하는 이유**
    ~~~
    테이블의 데이터는 순서 없이 쌓이게 되므로,
    특정 조건의 데이터를 찾으려면 테이블의 모든 데이터에 접근하여 비교하는 과정이 필요합니다. (full table scan) 
    하지만 인덱스가 있는 경우 search-key가 정렬되어 있기 때문에 조건 검색 시 속도가 빠릅니다.
    예를들어 만약 대량의 데이터를 가지고 있고 select ~ where 같은 특정 조건의 데이터를 찾을 때,
    인덱스를 활용하여 빠르게 데이터를 조회할 수 있습니다. (B+ 트리 관련)
    반대로 데이터의 양이 많지 않다면 굳이 인덱스를 사용할 이유가 없어집니다. 
    인덱스의 이점보다 추가 저장공간이나 데이터 수정에 대한 성능 저하가 더 크기 때문입니다.
    ~~~

* **어떠한 경우에 인덱스를 사용하면 좋을까?**
    * 규모가 작지 않은 테이블
    * INSERT, UPDATE, DELETE가 자주 발생하지 않는 컬럼
    * JOIN이나 WHERE 또는 ORDER BY에 자주 사용되는 컬럼
    * 데이터의 중복도가 낮은 컬럼 -> (Index의 자료구조가 트리(B+)일때 검색되는 대상이 증가하므로)

</div>
</details>


<details>
<summary><b>Index의 자료구조? (B+ Tree)</b></summary>
<div markdown="1">

* Index의 자료구조로 해시테이블을 생각해 볼 수 있는데, 해시함수는 값이 1만 달라도 다른 해시값을 생성하기 때문에
* 부등호 연산을 필요로 하는 검색이 필요한 경우 인덱스의 혜택을 받을 수 없다. (연속적인 접근이 불가능)
* 따라서 **B+ Tree**가 일반적으로 사용된다.
* B+ 트리의 특징
    * B+ 트리는 모든 key, Value가 리프노드에 모여있다. (Hash 아님! 따라서 key값을 통해 정렬과 연속된 접근이 가능함)
    * B+ 트리의 리프노드가 아닌 노드들에는 정렬을 위해 (Key,Value)에 대한 Index값과 위치가 저장되어 있다.
    * B+ 트리의 모든 리프노드는 연결리스트의 형태를 띄고 있어 데이터에 선형으로 접근이 가능하다. (다음노드 검색할때 루트부터 안해도 됨)
    * 순차검색을 할때 연결리스트를 순회하므로 효율적이다. (정렬이 되어 있기도 하고 캐시히트율이 높기 때문)
    * B+ 트리의 리프노드들은 오름차순으로 정렬된 형태를 갖는다.
    * B+ 트리는 균형트리이다. : 검색,삽입,삭제에 O(log2(N))이 보장된다.
    * B+ 예시
    * ![](https://velog.velcdn.com/images%2Femplam27%2Fpost%2F64290106-d927-4a82-9e08-8e52783c7dd3%2FDB%20%EC%9D%B8%EB%8D%B1%EC%8A%A4.jpg)

</div>
</details>


<details>
<summary><b>클러스터형(clustered) 인덱스와 보조형(non-clustered) 인덱스란 ?</b></summary>
<div markdown="1">

* 아직 이해못함 정리해야 함
* 클러스터형 인덱스 (Clustered Index)
* 보조 인덱스 (비클러스터형 인덱스 / Nonclustered Index)

</div>
</details>


<details>
<summary><b>정규화란? 정규화의 배경</b></summary>
<div markdown="1">

* 정규화가 생겨난 배경
    * 한 릴레이션(Relation)에 여러 엔티티의 속성을 혼합하면 정보가 중복 저장되며 저장 공간을 낭비하게 된다.
    * 또 중복된 정보로 인해 **이상 현상**이 발생하게 된다. 이러한 문제를 해결하기 위해 정규화 과정을 거치는 것이다.

<br>

* **정규화**란 Attribute 간의 종속성으로 인한 이상현상이 발생하는 관계를 분해하여 재디자인함으로써 **이상현상을 없애는 과정**
* **데이터의 중복 방지**, **데이터의 무결성**을 충족하기 위해 데이터베이스를 설계하는 방법
* 정규화에는 3가지 원칙이 있다.
    1. 정보의 무손실 : 분해된 릴레이션이 표현하는 정보는 분해되기 전의 정보를 모두 포함해야 한다.
    2. 최소 데이터 중복 : 이상 현상을 제거, 데이터 중복을 최소화
    3. 분리의 원칙 : 하나의 독립된 관계성은 하나의 독립된 릴레이션으로 분리해서 표현

</div>
</details>


<details>
<summary><b>반정규화란?</b></summary>
<div markdown="1">

* 반정규화(De-normalization)은 시스템의 성능 향상을 위해 정규화된 데이터 모델을 통합하는 작업이다
* 즉, 성능향상을 위해 의도적으로 정규화 원칙을 위배하는 행위이다. 따라서 정규화와 반정규화는 Trade-off 관계에 있다.
* 반정규화를 수행하면 테이블이 단순해지고 관리 효율성이 증가하지만, 데이터의 일관성이나 무결성이 보장되지 않을 수 있다.
* 반정규화의 대상
    1. 수행 속도가 많이 느린 경우 
    2. 테이블의 조인(JOIN)연산을 지나치게 사용하여 데이터를 조회하는 것이 기술적으로 어려운 경우 (Join없이 데이터 통합)
    3. 테이블에 많은 데이터가 있고, 다량의 범위 혹은 특정 범위를 자주 처리해야 하는 경우

</div>
</details>


<details>
<summary><b>정규화 이상현상</b></summary>
<div markdown="1">

* 이상현상이란 테이블 내의 데이터들이 불필요하게 **중복**되어 테이블을 조작할 때 발생되는 **데이터 불일치 현상**

1. 삽입 이상 (insertion anomaly)
    * 원하지 않는 자료가 삽입된다든지, 불필요한 데이터를 추가해야 삽입할 수 있는 문제점
    * 특정 데이터는 전혀 기록되지 않거나 불필요하여 기록되지 않는 경우가 발생
    * 아래의 그림은 course code가 없는 데이터를 삽입할 수 없어, 
        course code를 null로 하지 않는 이상 새 교수를 테이블에 추가할 수 없다.
    ![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/Insertion_anomaly.svg/420px-Insertion_anomaly.svg.png)

<br>

2. 삭제 이상 (deletion anomaly)
    * 데이터의 삭제가 전혀 다른 사실에 대한 데이터의 삭제도 필요로 하게 되는 현상
    * 아래의 그림에서 ENG-206 강의를 중단시 Dr. Giddens의 모든 정보가 삭제된다.
    ![](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Deletion_anomaly.svg/420px-Deletion_anomaly.svg.png)

<br>

3. 갱신 이상 (update anomaly)
    * 같은 정보가 복수개의 행에서 표현되어서 갱신은 논리적인 모순을 낳게 된다.
    * 아래의 그림에서 특정 직원의 주소 변경시 여러개의 레코드를 수정하여야 한다. 
        Employee 519는 하나의 레코드의 주소만 변경되어 다른 레코드에서 다른 주소를 가지고 있다.
    ![](https://upload.wikimedia.org/wikipedia/commons/thumb/1/12/Update_anomaly.png/420px-Update_anomaly.png)

</div>
</details>


<details>
<summary><b>함수의 종속성</b></summary>
<div markdown="1">

* [출처](https://rebro.kr/159)
* **함수 종속성(Functional Dependency)** 은 크게 3가지로 나뉜다.
    - 완전 함수 종속 : 기본키를 구성하는 모든 속성에 종속되는 경우
    - 부분 함수 종속 : 기본키를 구성하는 속성의 일부에 종속되거나, 기본키가 아닌 다른 속성에 종속되는 경우
    - 이행적 함수 종속 : A, B, C 세 속성이 있고 A→B, B→C 종속 관계가 있을 때, A→C가 성립하는 경우
* 이해를 돕기 위한 예시
    * 테이블에 학번,이름,학년,과목번호,성적 컬럼이 있고 기본키는 (학번,과목번호) 이다.
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FuFt88%2Fbtrat196XQO%2FMP47NALVFTkKLjSOI7HbxK%2Fimg.png)
    * 학년과 이름은 학번만 알아도 결정이 되지만 성적은 (학번,과목번호) 모두를 알아야 한다.
    * 따라서 학년과 이름은 (학번, 과목번호)에 대해 **부분 함수 종속**이고, 성적은 **완전 함수 종속**이다.

</div>
</details>


<details>
<summary><b>기본 키(primary key)와 후보키(Candidate Key) </b></summary>
<div markdown="1">

* 기본키는 관계에서 각 튜플(컬럼과 행(row) 중에서 행이라고 보면 됨)을 고유하게 식별하는 속성 또는 속성 집합
* 후보키는 관계에서 튜플을 고유하게 식별하는 키
* 예시
    * 학생테이블의 컬럼 : {ID, 성, 성, 나이, 주소, DOB, 부서 이름} 
    * 여기서는 {ID}, {First_name, Last_name, DOB}가 두 후보키 
    * 따라서 후보 키는 관계에서 튜플을 고유하게 식별할 수 있는 키라고 보면 됨
* 모든 기본 키는 후보 키이지만 반대의 경우는 아님

</div>
</details>


<details>
<summary><b>정규화의 종류</b></summary>
<div markdown="1">

* 정규화의 종류
    * 제1 정규형
    * 제2 정규형
    * 제3 정규형
    * BCNF 정규형

<br>

### 제1 정규형 (1NF)

1차 정규형은 각 로우마다 컬럼의 값이 1개씩만 있어야 한다. 이를 컬럼이 **원자값(Atomic Value)** 을 갖는다고 한다.

예를들어, 아래의 두 테이블은 제1 정규형을 만족하지 못한다.

<br>

* **Customer Table 1** 
    | Customer ID | Name | Telephone Number |
    |:-----:|:-----:|:--------------:|
    | 123 |	Robert | 555-861-2025 |
    | 456 | Jane | 555-403-1659, 555-776-4100, 555-808-2599 |
    | 789 | Maria | 555-808-9633 |

<br>

* **Customer Table 2** 
    | Customer ID | Name | Tel. No. 1 | Tel. No. 2 | Tel. No. 3 |
    |:-----:|:-----:|:------------:|:-----------:|:-----------:|
    | 123 |	Robert | 555-861-2025 | | |
    | 456 | Jane | 555-403-1659 | 555-776-4100 | 555-808-2599 |
    | 789 | Maria | 555-808-9633 | | |

<br>

제1 정규형을 적용시키면 아래와 같은 테이블로 나타낼 수 있다.

* **Customer Table**
    | Customer ID | First Name | Telephone Number |
    |:-----:|:-----:|:-----:|:--------------:|
    | 123 |	Robert | 555-861-2025 |
    | 456 | Jane | 555-403-1659 |
    | 456 | Jane | 555-776-4100 |
    | 456 | Jane | 555-808-2599 |
    | 789 | Maria | 555-808-9633 |

하지만 위 테이블은 갱신이상을 발생시킨다.

해당 문제는 2NF에서 해결이 가능하다.

<br> <br>

### 제2 정규형 (2NF)

제1정규형에 속하는 테이블이 제2정규형을 만족하기 위해서는 

부분 함수 종속을 제거하고 모든 속성이 기본키에 완전 함수 종속되도록 분해해야 한다.

1NF 테이블에서 복합키가 없다면, 자동으로 2NF를 만족한다.

예를들어 아래의 테이블은 2NF를 만족하지 못한다.

<br>

* **종업원의 기술**
    | 종업원 | 기술 | 근무지 |
    |:-----:|:-------:|:-------:|
    | Jones	| Typing | 114 Main Street |
    | Jones	| Shorthand | 114 Main Street |
    | Jones	| Whittling | 114 Main Street |
    | Bravo	| Light Cleaning | 73 Industrial Way |
    | Ellis	| Alchemy | 73 Industrial Way |
    | Ellis	| Flying | 73 Industrial Way |
    | Harrison | Light Cleaning | 73 Industrial Way |


{종업원} 이나 {기술}은 둘다 이 테이블의 후보키는 아니다. 

{종업원}은 다수의 기술을 가지고 있으면 테이블에 한 차례 이상 나타나기 때문이고

{기술} 또한 다수의 종업원이 같은 기술을 보유하고 있을때 테이블에 한 차례 이상 나타나기 때문.

오직 복합 키 {종업원, 기술}이 이 테이블의 후보 키이다.

그런데 남은 속성인 {근무지}는 후보 키의 일부분인 {종업원}에만 영향을 받는다. 그래서 위 테이블은 2NF가 아니다.

이때, 근무지를 변경한다면 갱신이상이 발생하므로 2NF에 맞게 테이블을 2개로 나누어 재설계하면 다음과 같다.

* **종업원**
    | 종업원 | 근무지 |
    |:-----:|:-------:|
    | Jones	| 114 Main Street |
    | Bravo	| 73 Industrial Way |
    | Ellis	| 73 Industrial Way |
    | Harrison | 73 Industrial Way |

* **종업원의 기술**
    | 종업원 | 기술 |
    |:-----:|:-------:|
    | Jones	| Typing |
    | Jones	| Shorthand |
    | Jones	| Whittling |
    | Bravo	| Light Cleaning |
    | Ellis	| Alchemy |
    | Ellis	| Flying |
    | Harrison | Light Cleaning |

<br>

그러나 모든 2NF 테이블이 갱신 이상이 없는 것은 아니다.

* **대회 우승자**
    | 대회 | 연도 | 우승자 | 우승자 생년 월일 |
    |:--------:|:----:|:--------:|:--------:|
    | Des Moines Masters | 1998 | Chip Masterson | 14 March 1977 |
    | Indiana Invitational | 1998 | Al Fredrickson | 21 July 1975 |
    | Cleveland Open | 1999 | Bob Albertson | 28 September 1968 |
    | Des Moines Masters | 1999 | Al Fredrickson | 21 July 1975 |
    | Indiana Invitational | 1999 | Chip Masterson | 14 March 1977 |

우승자와 우승자 생년월일이 {대회, 연도} 키에 의해 결정되지만, 우승자와 우승자 생년월일은 여러 개의 레코드에 중복되어 나타난다. 

이 점이 갱신 이상을 불러온다. 갱신시 주의하지 않으면 우승자는 여러 개의 생일을 가질 수 있다.

이 문제는 3NF에서 해결이 가능하다.

<br> <br> 

### 제3 정규형 (3NF)
제3 정규형을 만족하려면 아래와 같은 필요충분 조건이 있다.
1. 릴레이션 R(테이블)은 제2정규형이다.
2. 릴레이션 R의 키가 아닌 모든 컬럼이 릴레이션 R의 모든 키에 이행적 종속이 되지 않는다.
    (이행적 함수종속은 기능적 종속으로 X -> Y 이고 Y -> Z 에 의해서 X -> Z (X가 Z를 결정한다)가 되는 것이다.)
    즉, 이행적 종속이 되지 않는다는 것은 **테이블 내의 모든 속성이 기본 키에만 의존**해야하며, 다른 속성에 의존하지 않는다는 것

예를들어 아래의 테이블은 3NF를 만족하지 못한다.

<br>

* **대회 우승자**
    | 대회 | 연도 | 우승자 | 우승자 생년 월일 |
    |:--------:|:----:|:--------:|:--------:|
    | Des Moines Masters | 1998 | Chip Masterson | 14 March 1977 |
    | Indiana Invitational | 1998 | Al Fredrickson | 21 July 1975 |
    | Cleveland Open | 1999 | Bob Albertson | 28 September 1968 |
    | Des Moines Masters | 1999 | Al Fredrickson | 21 July 1975 |
    | Indiana Invitational | 1999 | Chip Masterson | 14 March 1977 |

{우승자}와 {우승자 생년월일}이 {대회, 연도} 후보키에 의해 결정되지만,

우승자 생년월일은 {우승자}에 의해서 결정된다. 즉, 생년월일 속성이 기본키가 아닌 다른 속성에 의존한다.

따라서 아래와 같이 테이블을 분리하여 변형하면 3NF를 만족할 수 있다.

* **대회 우승자**
    | 대회 | 연도 | 우승자 |
    |:--------:|:----:|:--------:|
    | Des Moines Masters | 1998 | Chip Masterson |
    | Indiana Invitational | 1998 | Al Fredrickson |
    | Cleveland Open | 1999 | Bob Albertson |
    | Des Moines Masters | 1999 | Al Fredrickson |
    | Indiana Invitational | 1999 | Chip Masterson |

<br>

* **우승자 생년월일**
    | 우승자 | 우승자 생년 월일 |
    |:--------:|:--------:|
    | Chip Masterson | 14 March 1977 |
    | Al Fredrickson | 21 July 1975 |
    | Bob Albertson | 28 September 1968 |
    | Al Fredrickson | 21 July 1975 |
    | Chip Masterson | 14 March 1977 |

<br> <br>

### BCNF 정규형 (Boyce-Codd Normal Form)
BCNF 정규형은 3.5 정규형이라고도 하며 아래와 같은 필요조건이 있다.
* 3NF의 모든 요구 사항을 충족
* 후보 키가 다른 속성에 부분적으로 의존하지 않는 경우 모든 테이블은 BCNF에 있다고 한다. 
    (x, y, z) 열이있는 모든 테이블에서 (x, y)-> z 및 z-> x이면 BCNF 위반이다. 
    (x, y)가 복합 키이고 (x, y)-> z이면 직접 또는 부분적으로 역 종속성이 없어야한다.

예를들어 아래의 테이블은 3NF를 만족하지만 BCNF를 만족하지 못한다.

<br>

* **학생의 수강 신청**
    | Student | Course | Professor |
    |:----:|:-------:|:----:|
    | Chip Masterson | Machine Learning | Andrew Ng |
    | Al Fredrickson | Java Programming | James Gosling |
    | Al Fredrickson | Machine Learning | Andrew Ng |
    | Bob Albertson | Java Programming | James Gosling |
    | Chip Masterson | Algorithm | Dijkstra |

{Student, Course} 를 기본키로 선정한 경우 3NF 까지 만족하지만 삽입이상, 갱신이상, 삭제이상이 생길 수 있다.

* 삽입이상
    * Algorithms 라는 수업이 Dijkstra 에 의해 열렸다고 하자. 하지만 수강생이 아무도 없는 경우 삽입할 수 없다.
* 갱신이상
    * James Gosling 이 담당하는 강의가 바뀌게 될 경우 수강생의 수만큼 갱신해줘야 하므로
    * 하나라도 빠뜨리면 데이터 불일치 문제가 발생할 여지가 있다.
* 삭제이상
    * Bob Albertson이 Java Programming수업을 수강취소하여 수강생이 없어지면 James Gosling 이라는 교수도 사라진다.

따라서 아래와 같이 테이블을 분리하면 BCNF를 만족할 수 있다.

* **학생의 수강 수업**
    | Student | Course |
    |:----:|:-------:|
    | Chip Masterson | Machine Learning |
    | Al Fredrickson | Java Programming |
    | Al Fredrickson | Machine Learning |
    | Bob Albertson | Java Programming |
    | Chip Masterson | Algorithm |

<br>

* **교수의 수업**
    | Professor | Course |
    |:-------:|:----:|
    | Andrew Ng | Machine Learning |
    | James Gosling | Java Programming |
    | Dijkstra | Algorithm |

</div>
</details>


<details>
<summary><b>Transaction 이란?</b></summary>
<div markdown="1">

* 트랜잭션(Transaction)은 데이터베이스의 상태를 변환시키는 **하나의 논리적 기능을 수행하기 위한 작업의 단위** 또는 **한꺼번에 모두 수행되어야 할 일련의 연산들**을 의미한다.


</div>
</details>


<details>
<summary><b>Transaction 특성(ACID)</b></summary>
<div markdown="1">

* ACID(원자성, 일관성, 고립성, 지속성)는
* 원자성(**A**tomicity): 트랜잭션이 데이터베이스에 모두 반영되던가, 아니면 전혀 반영되지 않아야 함
* 일관성(**C**onsistency): 하나의 트랜잭션 이전과 이후, 데이터베이스의 상태는 이전과 같이 유효해야 함
    * 트랜잭션이 일어난 이후의 데이터베이스는 데이터베이스의 제약이나 규칙을 만족해야 한다는 뜻
    * ex) 예를 들어 ‘모든 고객은 반드시 이름을 가지고 있어야 한다’는 데이터베이스의 제약이 있다고 가정한다.
    * 다음과 같은 트랜잭션은 Consistency(일관성)를 위반한다.
        * 이름 없는 새로운 고객을 추가하는 쿼리
        * 기존 고객의 이름을 삭제하는 쿼리
* 격리성(**I**solation): 모든 트랜잭션은 다른 트랜잭션으로부터 독립되어야 한다 (=고립성)
    * 둘 이상의 트랜잭션이 동시에 실행되고 있을 경우, 어떤 트랜잭션이라도 다른 트랜잭션의 연산에 끼어들 수 없음
    * 동시에 여러 개의 트랜잭션들이 수행될 때, 각 트랜젝션은 고립(격리)되어 있어 연속으로 실행된 것과 동일한 결과를 나타낸다.
* 영구성(**D**urability): 성공적으로 트랜잭션이 수행되었다면, 그 결과는 완전히 반영이 되어야 한다. 
    * 완전히 반영되면 로그를 남기게 되는데, 후에 이 로그를 이용해서 트랜잭션 수행전 상태로 되돌릴 수 있어야 한다. 
    * 때문에 트랜잭션은 로그저장이 완료된 시점에서 종료가 되어야 한다.

</div>
</details>


<details>
<summary><b>트랜잭션 격리수준(Transaction Isolation Levels)</b></summary>
<div markdown="1">

* [출처](https://joont92.github.io/db/%ED%8A%B8%EB%9E%9C%EC%9E%AD%EC%85%98-%EA%B2%A9%EB%A6%AC-%EC%88%98%EC%A4%80-isolation-level/)
* 트랜잭션 격리수준이란 동시에 여러 트랜잭션이 처리될 때, 트랜잭션끼리 얼마나 서로 고립되어 있는지를 나타내는 것
* 트랜잭션 격리수준은 고립도와 성능의 Trade-off 를 조절
* 고립도에 따라서 Transaction의 격리 수준을 4단계로 나누어 정의함
* 4가지 격리수준은 아래로 내려갈수록 트랜잭션간 고립 정도가 높아지며, 성능이 떨어지는 것이 일반적
* 일반적인 온라인 서비스에서는 READ COMMITTED나 REPEATABLE READ 레벨중 하나를 사용한다.
    * (oracle = READ COMMITTED, mysql = REPEATABLE READ)
* 4가지 격리수준 간단한 설명
    * READ UNCOMMITTED : 다른 트랜잭션에서 커밋되지 않은 내용도 참조할 수 있다
    * READ COMMITTED : 다른 트랜잭션에서 커밋되 내용만 참조할 수 있다.
    * REPETABLE READ : 트랜잭션에 진입하기 이전에 커밋된 내용만 참조할 수 있다. (하나의 트랜잭션은 하나의 스냅샷만 사용)
    * SERIALIZABLE : 트랜잭션에 진입하면 락을 걸어 다른 트랜잭션이 접근하지 못하게 한다.

<br>

* 격리수준에 따라 아래와 같은 부정합 문제들이 발생할 수 있음
* **Dirty Read**
    * 변경 후 아직 Commit 되지 않은 값 읽고, Rollback 후의 값을 다시 읽어 최종 결과 값이 상이한 현상
    * 예시
        ~~~
        A 트랜잭션에서 10번 사원의 나이를 27살에서 28살로 바꿈 (아직 커밋하지 않음)
        B 트랜잭션에서 10번 사원의 나이를 조회함
        28살이 조회됨 -> 이를 더티 리드(Dirty Read)라고 함
        A 트랜잭션에서 문제가 발생해 ROLLBACK했는데 B에서는 여전히 28살로 로직이 수행됨
        ~~~
* **NON-REPEATABLE Read**
    * 한 트랜잭션 내에서 같은 쿼리를 두번 수행할 때, 그 사이에 다른 트랜잭션이 값을 수정 또는 삭제함으로써 
    * 두 쿼리가 상이하게 나타나는 비 일관성이 발생하는 것
    * 예시
        ~~~
        B 트랜잭션에서 10번 사원의 나이를 조회, 27살이 조회됨
        A 트랜잭션에서 10번 사원의 나이를 27살에서 28살로 바꾸고 커밋
        B 트랜잭션에서 10번 사원의 나이를 다시 조회, 28살이 조회됨
        즉, 똑같은 SELECT를 수행했는데 다른 결과가 반환이 되어 트랜잭션 B에서 문제가 생길 수 있음
        ~~~
* **Update 부정합**
    * REPETABLE READ 레벨에서 UPDATE 쿼리로 인해 발생하는 문제임
    * 예시
        ~~~sql
        START TRANSACTION; -- transaction id : 1
        SELECT * FROM Member WHERE name='junyoung';

            START TRANSACTION; -- transaction id : 2
            SELECT * FROM Member WHERE name = 'junyoung';
            UPDATE Member SET name = 'joont' WHERE name = 'junyoung';
            COMMIT;

        UPDATE Member SET name = 'zion.t' WHERE name = 'junyoung'; -- 0 row(s) affected
        COMMIT;
        ~~~
        * 트랜잭션2에서 name = junyoung이 joont로 바뀜
        * 트랜잭션1에서 name = junyoung을 조회하지만 Undo영역에서만 조회가 됨(트잭2에서 joont으로 바뀌었기 때문)
        * Undo영역의 데이터는 쓰기 lock을 걸 수 없기 때문에 아무 일도 일어나지 않음
        * name 결과는 트잭2에서 바뀐 내용이 적용이 됨. 따라서 name = joont
* **Phantom Reads**
    * 하나의 트랜잭션에서 같은 쿼리를 두 번 실행했을 경우, 첫 번째 쿼리에서 없던 유령(Phantom) 레코드가 두 번째 쿼리에서 나타나는 현상
    * Insert 쿼리에 대해서만 나타나는 현상
    * 예시
        ~~~
        START TRANSACTION; -- transaction id : 1 
        SELECT * FROM Member; -- 0건 조회

            START TRANSACTION; -- transaction id : 2
            INSERT INTO MEMBER VALUES(1,'joont',28);
            COMMIT;

        SELECT * FROM Member; -- 여전히 0건 조회 
        UPDATE Member SET name = 'zion.t' WHERE id = 1; -- 1 row(s) affected
        SELECT * FROM Member; -- 1건 조회 (REPETABLE READ에 에 의하면 원래 출력되지 않아야 함)
        COMMIT;
        ~~~


<br>

* 4가지 격리수준 상세설명
1. **READ UNCOMMITTED**
    * 어떤 트랜잭션의 변경내용이 COMMIT이나 ROLLBACK과 상관없이 다른 트랜잭션에서 보여진다.
    * **Dirty Reads, Non-Repeatable Reads, Phantom Reads** 가 모두 발생 가능
    * 데이터의 정합성 문제가 많아 RDBMS 표준에서는 격리수준으로 인정하지도 않음
2. **READ COMMITTED**
    * 오라클 DBMS에서 기본으로 사용하고 있고, 온라인 서비스에서 가장 많이 선택되는 격리수준
    * 어떤 트랜잭션의 변경 내용이 COMMIT 되어야만 다른 트랜잭션에서 조회할 수 있다.
    * 읽기 락을 유지하지 않기 때문에 **Non-Repeatable Reads** 와 **Phantom Reads** 는 여전히 발생
3. **REPEATABLE READ**
    * MySQL DBMS에서 기본으로 사용하고 있고, NON-REPEATABLE READ 문제를 해결한 격리수준이다.
    * 하나의 트랜잭션내에서 똑같은 SELECT를 수행했을 경우 항상 같은 결과를 반환해야 한다.
    * 트랜잭션이 시작되기 전에 커밋된 내용에 대해서만 조회할 수 있는 격리수준이다.
        * 실제 테이블 값을 가져오는 것이 아니라 Undo 영역에 백업된 레코드에서 값을 가져온다.
    * 즉, 자신의 트랜잭션 번호보다 낮은 트랜잭션 번호에서 커밋된 내용만 보게 되는 것ㅂ
        * 트랜잭션은 고유한 트랜잭션 번호(증가하는)를 가지고 있으며, 언두 영역의 레코드는 변경을 발생시킨 트랜잭션의 번호가 포함
    * 범위(예를들어 Select)락을 관리 하지 않아 **Update 부정합** 과 **Phantom Reads** 가 발생 가능
4. **SERIALIZABLE**
    * 가장 단순하고 엄격한 트랜잭션 격리 수준
    * 기본적으로 순수한 SELECT 작업은 아무런 잠금을 걸지않고 동작하는데 반해
    * SELECT에 대해 범위락을 설정하고 읽기 쓰기 락을 트랜잭션 종료까지 유지한다.

<br>

* 아래의 그림으로 한눈에 비교할 수 있음. (SERIALIZABLE의 굵은 화살표는 범위lock을 나타냄)
![](https://miro.medium.com/max/475/1*hEpucQJzGE6K7D9M_0bEVw.gif)

</div>
</details>


<details>
<summary><b>NoSQL 이란? 장단점?</b></summary>
<div markdown="1">

* [출처](https://code-lab1.tistory.com/53)
* NoSQL은 비관계형 데이터베이스를 지칭한다.
* 즉, RDBMS 형태의 관계형 데이터베이스가 아닌 다른 형태의 데이터 저장 기술이다.
* 관계형 데이터베이스의 한계를 극복하기 위한 형태이며 대량의 분산된 데이터를 저장하고 조회하는 데 특화되었다.
* 스키마 없이 사용 가능하거나 느슨한 스키마를 제공하는 저장소이다.

<br>

* NoSQL의 장점
    1. RDBMS에 비해 저렴한 비용으로 분산처리와 병렬 처리 가능
    2. 비정형 데이터 구조 설계로 설계 비용 감소
    3. Big Data 처리에 효과적
    4. 가변적인 구조로 데이터 저장이 가능
    5. 데이터 모델의 유연한 변화가 가능
* NoSQL의 단점
    1. 데이터 업데이트 중 장애가 발생하면 데이터 손실 발생 가능
    2. 많은 인덱스를 사용하려면 충분한 메모리가 필요. 인덱스 구조가 메모리에 저장
    3. 데이터 일관성을 항상 보장하지 못함
* 대표적으로 Redis와 MongoDB가 있음
    * Redis는 조회성능 향상을 위한 캐시사용을 목적으로 많이 사용함

</div>
</details>