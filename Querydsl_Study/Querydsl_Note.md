# Querydsl Note

<br> <br>

### 1. querydsl의 장점
* 문자가 아닌 코드로 작성 -> 쿼리의 문법이나 파라미터명에 오타가 생기면 **컴파일** 시점에 오류를 잡을 수 있다.
* IDE의 도움을 받을 수 있다. (ex 파라미터 바인딩 알아서 해줌)
* 동적 쿼리 작성이 편리하다.
* JPQL이 제공하는 모든 검색조건 제공
* 제약조건을 조립할 수 있고 재사용할 수 있다.



<br> <br>

### 2. Q클래스 인스턴스를 사용하는 2가지 방법, 활용
* 방법 1
~~~java
// 별칭(Alias) 직접 지정 -> 같은 테이블을 조인하는 경우가 아니면 쓸일이 없음
QMember qMember = new QMember("m"); 
~~~

* 방법 2
~~~java
// 별칭(Alias)은 Q파일에서 확인가능
QMember qMember = QMember.member; // 기본 인스턴스 사용
~~~

* 방법2와 static import를 활용하는 방식이 가장 깔끔한 방법
* 예시코드
~~~java
// 원래는 member가 아니라 QMember.member가 와야하지만 QMember를 static import하여 member로 사용
Member findMember = queryFactory
        .select(member)
        .from(member)
        .where(member.username.eq("member1"))
        .fetchOne();
~~~


<br> <br>

### 3. querydsl로 생성되는 jpql 로그로 확인하기
* yml파일에 아래의 설정정보 추가
~~~yml
spring:
    jpa:
        properties:
            hibernate:
                use_sql_comments: true
~~~



<br> <br>

### 4. selectFrom()
* .select(m).from(m) 일때 selectFrom(m)으로 합칠 수 있음



<br> <br>

### 5. JPQL이 제공하는 모든 검색 조건 제공

* 코드예시
~~~java
member.username.eq("member1") // username = 'member1'
member.username.ne("member1") //username != 'member1'
member.username.eq("member1").not() // username != 'member1'
member.username.isNotNull() //이름이 is not null
member.age.in(10, 20) // age in (10,20) -> 10 or 20
member.age.notIn(10, 20) // age not in (10, 20)
member.age.between(10,30) //between 10, 30 -> 10 ~ 30
member.age.goe(30) // age >= 30
member.age.gt(30) // age > 30
member.age.loe(30) // age <= 30
member.age.lt(30) // age < 30
member.username.like("member%") //like 검색
member.username.contains("member") // like ‘%member%’ 검색
member.username.startsWith("member") //like ‘member%’ 검색
~~~



<br> <br>

### 6. where절 조건 (method chaining) VS (',')
* 결론만 말하면 ','를 이용하여 조건을 추가하는것이 좋음
* 동적쿼리를 더 깔끔하게 짤 수 있기 때문 (Todo : 공부하고 내용 추가하기)
~~~java
Member findMember = queryFactory
        .selectFrom(member)
        .where(
            member.username.eq("member1"), // chaining하지 않고 ','로 추가해도 and로 처리가능
            member.age.eq(10) // chaining하려면 and(member.age.eq(10)) 가 되어야 함
        )
        .fetchOne();
~~~



<br> <br>

### 7. 결과조회(List or 단건)
* fetch() : 리스트 조회, 데이터 없을시 빈 리스트 반환
* fetchOne() : 단건 조회
    - 결과 없을시 null
    - 결과가 둘 이상이면 NonUniqueResultException 발생
* fetchFirst() : `limit(1).fetchOne()`
* fetchResults() : 페이징 정보 포함, total count 쿼리 추가 실행 (Todo : deprecate됨, 따로 찾아보기)
* fetchCount() : count쿼리로 변경해서 count 수 조회




<br> <br>

### 8. 




<br> <br>

### 9. 




<br> <br>

### 10. 




<br> <br>

### 11. 




<br> <br>

### 12. 




<br> <br>

### 13. 




<br> <br>

### 14. 




<br> <br>

### 15. 





<br> <br>

