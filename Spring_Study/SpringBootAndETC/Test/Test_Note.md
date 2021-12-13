# Test Note

******
### 1. Mockito에서 사용하는 Annotation

* `@ExtendWith(MockitoExtension.class)`
    테스트 클래스가 Mockito를 사용함을 의미
    테스트클래스 위에 붙여주면 됨

* `@Mock`
    실제 구현된 객체 대신에 Mock 객체를 사용하게 될 클래스를 의미합니다.
    테스트 런타임 시 해당 객체 대신 Mock 객체가 주입되어 Unit Test가 처리됩니다.

* `@InjectMocks`
    Mock 객체가 주입된 클래스를 사용하게 될 클래스를 의미합니다. 
    테스트 런타임 시 클래스 내부에 선언된 멤버 변수들 중에서 @Mock으로 등록된 클래스의 변수에 실제 객체 대신 Mock 객체가 주입되어 Unit Test가 처리됩니다.



<br> <br>

******
### 2. Mock객체 행동패턴
* Stubbing 이란 ?
    Mock객체의 행동을 조작하는것임

모든 Mock 객체의 행동패턴
1. 리턴값이 있는 메소드는 모두 Null을 리턴 (Optional타입은 Optional.empty 반환)
2. Primitive 타입은 기본 Primitive값으로 정의됨
3. 컬렉션은 비어있는 콜렉션을 만들어줌
4. Void메소드는 예외를 던지지 않고 아무런 일도 발생하지 않는 것처럼 동작됨
    * 예를들어 어떤 엔티티의 service클래스의 Mock객체에 void validate(...)라는 메소드를
      실행시키면 아무일도 일어나지 않음




<br> <br>

******
### 3. Stubbing 이란 ?
Mock객체의 행동을 조작하는것임
Stubbing하면 위에서 `2. Mock객체 행동패턴`에 대한 내용을 조작할 수 있음



* 예시
    1. 특정 매개변수를 받을 경우 특정한 값을 리턴하거나 예외를 발생시키도록 할 수 있음
    2. Void메소드가 특정 매개변수를 받거나 호출된 경우 예외를 발생시킬 수 있음
    3. 메소드가 동일한 매개변수로 여러번 호출되더라도 호출되는 순서에 따라 다르게 Stubbing가능

* 코드
~~~java
@Mock MemberService memberService;

Member member = new Member();
member.setId(1L);
member.setEmail("jcu011@naver.com");

// stubbing 예시들(위의 예시 1,2,3)
// 반드시 findById에 1L이 들어 올때만 위에 정의한 member가 반환되도록 조작 (1의 내용)
when(memberService.findById(1L)).thenReturn(Optional.of(member));

// 아래처럼 any()를 사용하면 값을 특정하는게 아니라 아무 값이 들어와도 위에서 정의한 member를 반환 (1의 내용)
when(memberService.findById(any())).thenReturn(Optional.of(member));

// 2L이 들어오면 RTE 발생하도록 stubbing (1의 내용)
when(memberService.findById(2L)).thenThrow(new RuntimeException());

// memberService에서 validate메소드에 1L이 입력되어 호출되면 예외발생하도록 stubbing (2의 내용)
doThrow(new IllegalArgumentException()).when(memberService).validate(1L);

// 첫번째 호출은 member, 두번째 호출은 RTE, 세번째는 Optional.empty를 반환하도록 stubbing
when(memberService.findById(any()))
    .thenReturn(Optional.of(member));
    .thenReturn(new RuntimeException());
    .thenReturn(Optional.empty);

~~~




<br> <br>

******
### 4. Mock 객체 확인
Mock 객체가 어떻게 사용이 됐는지 확인할 수 있다.
* 특정 메소드가 특정 매개변수로 몇번 호출 되었는지, 최소 한번은 호출 됐는지, 전혀 호출되지 않았는지
[Verifying exact number of invocations](https://javadoc.io/doc/org.mockito/mockito-core/latest/org/mockito/Mockito.html#exact_verification)

* 어떤 순서대로 호출했는지
[Verification in order](https://javadoc.io/doc/org.mockito/mockito-core/latest/org/mockito/Mockito.html#in_order_verification)

* 특정 시간 이내에 호출됐는지
[Verification with timeout](https://javadoc.io/doc/org.mockito/mockito-core/latest/org/mockito/Mockito.html#verification_timeout)

* 특정 시점 이후에 아무 일도 벌어지지 않았는지
[Finding redundant invocations](https://javadoc.io/doc/org.mockito/mockito-core/latest/org/mockito/Mockito.html#finding_redundant_invocations)




<br> <br>

******
### 5. BDD (Behaviour-Driven Development) 스타일 코드
when이나 verify는 BDD에 맞게 메소드이름이 따로 정의되어 있음
given이나 then으로 대체 가능함

* 코드예시
~~~java

@ExtendWith(MockitoExtension.class)
class StudyServiceTest {

    @Mock MemberService memberService;
    @Mock StudyRepository studyRepository;

    @Test
    void createNewStudy() {
        // Given
        StudyService studyService = new StudyService(memberService, studyRepository);
        assertNotNull(studyService);

        Member member = new Member();
        member.setId(1L);
        member.setEmail("keesun@email.com");

        Study study = new Study(10, "테스트");

        // when(memberService.findById(1L)).thenReturn(Optional.of(member));
        // when(studyRepository.save(study)).thenReturn(study);
        // BDD에 어울리게 when대신 given, thenReturn대신 willReturn
        given(memberService.findById(1L)).willReturn(Optional.of(member));
        given(studyRepository.save(study)).willReturn(study);

        // When
        studyService.createNewStudy(1L, study);

        // Then
        assertEquals(1L, study.getOwnerId());
        
        // verify(memberService, times(1)).notify(study); 
        // verifyNoMoreInteractions(memberService); 
        // BDD에 어울리게 verify대신 then
        then(memberService).should(times(1)).notify(study); // notify(study)가 한번만 실행된다. -> 아니면 test실패
        then(memberService).shouldHaveNoMoreInteractions(); // 위의 then이후 더이상 실행되는 코드가 없다. -> 아니면 test실패
    }


~~~



<br> <br>

******
### 6. @Mock 과 @InjectMocks 의 차이점
둘다 `@ExtendWith(MockitoExtension.class)`가 붙어 있어야 사용가능 !

**차이점**
* `@Mock`은 Mock객체를 생성해 줍니다. 
* `@InjectMocks`가 붙은 mock객체에 다른 mock객체를 주입하여 사용할 수 있습니다.




<br> <br>

******
### 7. Argumentmatcher
다양한 인자에 대해서 테스트 하고 싶을때 Argumentmatcher를 사용할 수 있음

단, 서비스 메서드에 인자를 넘겨줄 때 argumentmatcher를 한 인자에 사용하면
다른 모든 인자도 argumentmatcher로 넘겨주어야 한다.

* 예시 코드
~~~java
abstract class FlowerService {
    public abstract boolean isABigFlower(String name, int petals);
}

FlowerService mock = mock(FlowerService.class);

// 잘못된 Argument matcher 사용
when(mock.isABigFlower("poppy", anyInt())).thenReturn(true);

// 모든 인자가 Argumentmatcher이어야 하므로 eq()를 씌워줌
when(mock.isABigFlower(eq("poppy"), anyInt())).thenReturn(true);
~~~





<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 




<br> <br>

******
### 3. 



