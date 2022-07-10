# SpringSecurity


<details>
<summary><b>SecurityContextHolder, SecurityContext, Authentication</b></summary>
<div markdown="1">

![](https://docs.spring.io/spring-security/reference/_images/servlet/authentication/architecture/securitycontextholder.png)

* SecurityContextHolder는 전략패턴과 ThreadLocal 변수를 통해서SecurityContext 데이터를 쓰거나 읽을수 있는 API를 제공
* SecurityContext와 Spring Web MVC
    * Spring Web MVC는 Thread Per Request 모델을 기반으로 함 -> ThreadPool을 사용함
    * SecurityContext도 ThreadLocal을 기반으로 동작하기 때문에, Spring Web MVC에서 Controller, Service, Repository, 도메인모델 어느 부분에서든 SecurityContextHolder를 통해서 SecurityContext를 조회할 수 있음
* SecurityContext는 Authentication을 보관하는 역할을 하며, SecurityContext를 통해 Authentication인터페이스의 구현체를 꺼내올 수 있음
* Authentication은 현재 접근하는 주체의 정보와 권한을 담는 인터페이스
* Authentication 인터페이스 구현체는 Principal, Credentials, Authorities, Authenticated와 같은 필드를 가지고 있음
    * Principal : 인증전이면 String값(로그인ID), 인증후라면 User객체
    * Authorities : 사용자의 권한 목록
    * Credentials : 주로 비밀번호 같은 값
    * Authenticated : 인증여부
    * Authentication 인터페이스
        ~~~java
        public interface Authentication extends Principal, Serializable {
            //현재 사용자의 권한 목록을 가져옴
            Collection<? extends GrantedAuthority> getAuthorities();
            //credentials(주로 비밀번호)를 가져옴 
            Object getCredentials();
            // Returns:additional details about the authentication request(IP address, certificate serial number etc.), or null if not used
            Object getDetails();
            //Principal 객체를 가져옴
            Object getPrincipal();
            //인증 여부를 가져옴
            boolean isAuthenticated();
            //인증 여부를 설정함
            void setAuthenticated(boolean isAuthenticated) throws IllegalArgumentException;
        }
        ~~~

</div>
</details>
