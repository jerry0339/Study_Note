# Network 요약

<details>
<summary><b>제목</b></summary>
<div markdown="1">

* 내용

</div>
</details>

<details>
<summary><b>OSI 7 계층</b></summary>
<div markdown="1">

* 네트워크에서 통신이 일어나는 과정을 7단계로 나눈 것
* 7계층
    1. 물리 : 데이터를 전기적인 신호로 변환해서 주고받는 기능을 진행하는 공간
    2. 데이터링크 : 물리계층으로부터 송수신되는 정보의 오류와 흐름을 관리하여 안전한 정보의 전달을 수행할 수 있도록 함
    3. 네트워크 : 데이터를 목적지까지 전달하는 역할. 라우터를 통해 IP주소를 지정하고 패킷을 전달
    4. 전송 : TCP / UDP 프로토콜이 수행됨
    5. 세션 : TCP/IP 세션을 유지하거나 없애는 역할
    6. 표현 : 데이터의 형식차이를 일관성 있게 제공함, 데이터의 암호화, 압축, 인코딩이 이루어짐
    7. 응용 : 최종 목적지로, 응용 프로세스와 직접 관계하여 일반적인 응용 서비스를 수행 (ex HTTP프로토콜 수행)

</div>
</details>


<details>
<summary><b>IP란?</b></summary>
<div markdown="1">

* IP(Internet Protocol)
~~~
인터넷에 연결되어 있는 모든 장치들을 식별할 수 있도록 부여되는 고유 주소
IP를 통해 패킷을 전달할 수 있음
~~~

* IP의 한계
    * 비연결성 : 패킷을 받을 대상이 없거나 서비스 불능 상태여도 패킷 전송
    * 비신뢰성 : 패킷의 순서가 바뀌거나 패킷이 누락될 수 있음
    * 프로그램의 구분 : 같은 IP를 사용하는 서버에서 통신하는 어플리케이션이 둘 이상? (Port 관련)
    * TCP, UDP가 나오게된 계기

</div>
</details>


<details>
<summary><b>패킷이란?</b></summary>
<div markdown="1">

* Package(화물)와 Bucket(덩어리)의 합성어
* IP주소로 데이터가 전송될 때 서로 교환되는 실제의 내용물

</div>
</details>


<details>
<summary><b>PORT란 ?</b></summary>
<div markdown="1">

* 같은 IP 내에서 프로세스를 구분하기 위해 사용하는것
* TCP or UDP에서는 출발PORT , 도착PORT가 패킷에 함께 전달되어 사용됨

</div>
</details>


<details>
<summary><b>DNS란 ?</b></summary>
<div markdown="1">

* IP는 기억하기 어렵다.
* IP는 변경될 수 있다.
* 따라서 IP를 DNS서버에 도메인명으로 등록하여 사용하는 것임
* HTTP 1.1 부터는 IP하나에 여러 도메인을 등록하여 버츄얼 호스팅이 가능하다는 장점이 있다.

</div>
</details>


<details>
<summary><b>URI란 ?</b></summary>
<div markdown="1">

* URI(Uniform Resource Identifier) 는 네트워크 상 자원을 가리키는 일종의 고유 식별자(ID) 이다.
* URI = URL + URN 이다.
* 이름만으로 리소스를 찾는 방법인 URN은 보편화 되어 있지 않으므로 URN은 거의 사용하지 않는다.
* URL을 주로 사용하기 때문에 URL과 URI를 같은 의미로 사용되고 있다.

</div>
</details>


<details>
<summary><b>TCP/IP와 UDP</b></summary>
<div markdown="1">

* TCP(Transmission Control Protocol) 란
    * 서버와 클라이언트간에 데이터를 신뢰성 있게 전달하기 위해 만들어진 프로토콜
    * IP와 함께 TCP/IP라는 명칭으로도 불림

* TCP 특징
    * **연결 지향** - 3 way handshake
    * 신뢰할 수 있는 프로토콜 - 데이터 전달 보증, 순서 보장 (패킷안에 관련정보가 있음)
    * HTTP/1.1 , HTTP/2 에서 사용
    * 하지만 데이터량이 크고, 전송속도가 UDP에 비해 떨어짐

<br>

* UDP (User Datagram Protocol) 란?
    * IP(인터넷 프로토콜)와 똑같다. PORT와 체크섬(오류검출) 정도만 추가됨
* UDP 특징
    * TCP와는 달리 데이터 연결, 데이터 전달, 패킷 순서를 보장하지 못함
    * 하얀 도화지와 같음 - 전달 목적에 맞게 최적화 할 수 있음 -> **HTTP/3** 의경우 UDP를 최적화한 버전임
    * IP와 거의 같은데 PORT, 체크섬 정도만 추가됨
    * TCP에 비해 데이터량이 적고 전송속도가 빠름

</div>
</details>


<details>
<summary><b>TCP 3 way handshake & 4 way handshake</b></summary>
<div markdown="1">

* 3 Way Handshake는 TCP/IP 프로토콜 세션을 수립하는 과정이다.
![](https://t1.daumcdn.net/cfile/tistory/225A964D52F1BB6917)

<br>

* 4way handshake를 통해 연결을 종료 세션을 종료할 수 있다.
* 4way handshake에서 Time wait는 마지막에 클라가 Ack->한 이후에 이루어짐
* Time wait가 필요한 이유는 서버의 <-Fin 응답 뒤에 응답데이터가 더 올 수 있기 때문에 조금 더 기다려야 함
![](https://t1.daumcdn.net/cfile/tistory/2152353F52F1C02835)

</div>
</details>


<details>
<summary><b>HTTP 통신 Socket 통신의 차이점?</b></summary>
<div markdown="1">

* HTTP는 요청과 응답이 이루어지면 연결이 끊어지지만 Socket통신은 유지됨
* 즉, HTTP통신은 클라가 요청하면 서버가 응답하는 단방향 통신이고
* Socket통신은 클라와 서버 양쪽에서 서로 데이터를 전달하는 양방향 통신이다.

</div>
</details>


<details>
<summary><b>대칭키, 공개키, 전자서명, 인증서란 ?</b></summary>
<div markdown="1">

* [출처](https://mysterico.tistory.com/30)
* **대칭키** : 암호화에 쓰이는 키와 복호화에 쓰이는 키가 동일한 기법
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FW94Qi%2Fbtq0teEbVJK%2FWKelKm2z3UqPpQOCQ2KKL0%2Fimg.png)
* **공개키(비대칭 키)** : 공개키와 개인키(비밀키)라는 2가지 키를 사용하는 기법
    * 공개키는 말그대로 모두에게 공개되어 있는 키, 개인키는 한 사람만 알고 있는 것임
    * 공개키를 통해 암호화된 문서는 개인키를 통해 복호화 할 수 있음
    * 개인키를 통해 암호화된 문서는 공개키를 통해 복호화 할 수 있음
    ![](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FAGD4h%2Fbtq0pypJPGx%2FkkTh7vd6VMgrbRnJAF8KH0%2Fimg.png)
* **인증(전자서명)** 과정
    1. 인터넷 사이트는 자신의 정보와 공개키를 인증기관에 제출
    2. 인증 기관은 검증을 거친 후 사이트 정보와 공개키를 인증기관의 개인키로 암호화 -> **사이트 인증서**
    3. 인증 기관은 웹 브라우저에게 자신의 공개키를 제공
    4. 사용자가 웹브라우저로 사이트에 접속하면 사이트는 자신의 인증서를 웹 브라우저(사용자)에게 보냄
    (2.에서 인증기관의 개인키로 암호화한 사이트의 정보와 공개키가 들어있음)
    5. 웹 브라우저(사용자)는 인증 기관의 공개키로 서버 인증서를 해독하여 검증
    6. 이렇게 얻은 사이트 공개키로 대칭키를 암호화하여 보냄
    7. 사이트는 자신의 개인키로 암호문을 해독해서 대칭키를 얻음
    8. 이제 대칭키로 암호문을 주고 받을 수 있음

</div>
</details>


<details>
<summary><b>SSL/TLS 란?</b></summary>
<div markdown="1">

* SSL(Secure Socket Layer)이란 보안 소켓 계층을 이르는 것으로, 데이터를 안전하게 전송하기 위한 인터넷 암호화 통신 프로토콜임
* TLS는 SSL의 업데이트 버전으로 SSL의 명칭이 TLS로 바뀐것임
* SSL의 동작방식 (자세한 동작방식은 전자서명 내용 참고)
    ```
    응용계층의 프로토콜들은 외부로 보내는 데이터를 TCP가 아닌 SSL를 통해 보내게 되고,
    SSL은 받은 데이터를 암호화하고 TCP를 통해 데이터를 전송함.

    전달 받을 때에도 TCP를 통해 받은 데이터를 복호화하여 응용계층에 전달하게 되는데,
    이 과정에서 Application은 SSL을 TCP로 인식하고, TCP는 SSL을 Application으로 인식하기 때문에,
    Application과 TCP사이의 데이터 전달 방식은 기존 전달 방식을 그대로 사용하게 됨.

    즉, 전송계층(TCP)과 응용계층 사이에서 동작하며 데이터를 암호화시키는 역할을 함
    ```

</div>
</details>


<details>
<summary><b>HTTPS란, 동작방식 ?</b></summary>
<div markdown="1">

* HTTPS (HyperText Transfer Protocol Secure)
* [출처](https://nuritech.tistory.com/25)
* HTTPS란 HTTP의 보안처리가 된 버전이 HTTPS이며 요즘엔 웹의 기본스펙으로 여겨짐
* HTTPS는 TCP 위에 SSL/TLS 층을 추가하여 암호화, 인증 그리고 무결성 보장을 통해 더 안전하게 만들어주는 프로토콜
* HTTPS 프로토콜을 사용하기 위해서는 인증기관(CA)으로 부터 SSL 인증서를 발급받아야 함
* 서버에서 HTTPS 프로토콜 사용을 위해 SSL 인증서를 발급받는 과정
    * 
* HTTPS는 대칭키와 공개키를 모두 사용하는 하이브리드 방식임
* 데이터 전송을 위해 대칭키 방식을 사용하며 대칭키를 안전하게 전달하기 위해 공개키 방식을 사용

* 자세한 내용 추가!!

</div>
</details>


<details>
<summary><b>웹 브라우저 요청 흐름</b></summary>
<div markdown="1">

* `https://www.google.com:443/search?q=hello&hl=ko` 와 같은 요청이 오면 어떤 과정을 거치게 될까?

<br>

1. 웹 브라우저가 DNS서버에서 IP를 조회한다.
2. scheme가 https이므로 443포트가 생략되어 있음
3. HTTP요청 메시지를 생성함
4. 조회한 IP와 포트의 위치로 Socket 라이브러리를 통해 HTTP메시지를 전달
5. 전달할 때에는 3way handshake로 TCP/IP연결
6. HTTP메시지를 포함한 TCP/IP 패킷을 생성하여 전달
7. 서버는 전달받은 패킷의 HTTP 메시지를 해석하여 요청을 처리
8. 서버에서 HTTP 응답 메시지를 생성하여 클라이언트에게 전달
9. 4way handshake를 통해 연결을 종료

</div>
</details>


<details>
<summary><b>HTTP 특징: 비연결성과 무상태</b></summary>
<div markdown="1">

* HTTP는 비연결성(Connectionless) 프로토콜이다.
    * 클라이언트가 서버에 요청을 하고 응답을 받으면 바로 TCP/IP 연결을 끊어 연결을 유지 하지 않는 것
    * 이를 통해 서버의 자원을 효율적으로 관리하고, 수 많은 클라이언트의 요청에도 대응할 수 있게 함
* HTTP는 무상태(Stateless) 프로토콜이다.
    * 서버가 클라이언트의 이전 상태를 보존하지 않는다는 의미

</div>
</details>


<details>
<summary><b>HTTP 메소드</b></summary>
<div markdown="1">

* HTTP 메소드는 클라이언트가 웹 서버에게 사용자 요청의 목적이나 종류를 알리는 수단
* 멱등 : 한 번 호출하든 두 번 호출하든 결과가 같은 것을 의미
    * POST만 멱등하지 않음
* 안전 : 리소스를 변경하지 않는, 즉 읽기전용 메서드
    * (GET, HEAD)를 말한다.
* 캐시가능(Cacheable Methods) 
    * 모두 캐시가능하지만 주로 GET, HEAD에서만 사용한다.
* 주요 메소드 종류
    * GET : 리소스 조회 
    * POST : 요청 데이터 처리, 주로 데이터 등록에 사용
    * PUT : 리소스를 대체, 해당 리소스가 없으면 생성
    * PATCH : 리소스를 일부만 변경
    * DELETE : 리소스 삭제

</div>
</details>


<details>
<summary><b>HTTP 1.0, 1.1, 2.0, 3.0 차이점</b></summary>
<div markdown="1">

* HTTP 1.0과 1.1의 차이점을 1.1의 특징을 통해 설명하면 다음과 같다.
* **HTTP 1.1의 큰 특징**
    1. 커넥션 유지 (Persistent Connection)
        ~~~
        HTTP를 이용한 데이터 전달은 TCP세션 기반에서 이루어진다.
        HTTP 1.1에서는 1.0과는 달리 TCP세션을 지속적으로 유지할 수 있는데에 차이가 있다.
        ~~~
    2. 파이프라이닝 (Pipelining)
        ~~~
        HTTP 요청은 순차적으로 이루어 지는데 파이프라이닝을 이용하면
        같은 TCP세션에서 동시에 요청을 여러개 보내고 이에 대한 각각의 응답을 받아 처리할 수 있다.
        단, 결국엔 응답은 요청한 순서에 따라 받아야 하는 head of line blocking 문제가 있다.
        ~~~
    3. 호스트 헤더 (Host Header)
        ~~~
        HTTP 1.0 에서는 하나의 IP에 여러 도메인을 운영할 수 없지만
        HTTP 1.1 부터는 Host 헤더의 추가를 통해 버츄얼 호스팅이 가능해 졌다.
        ~~~
    4. 강력한 인증 절차 (Improved Authentication Procedure)
        ~~~
        HTTP 1.0에서도 클라이언트의 인증을 요구하는 헤더(www-authentication)는 지원되어 왔으나
        클라이언트와 서버 사이에 프록시가 위치하는 경우 사용자의 인증을 요구할 수 있는 방법이 없었다.
        HTTP 1.1 에서는 proxy-authentication, proxy-authorization 헤더 추가를 통해 인증 요구 문제를 해결했다.
        ~~~
* HTTP 1.1과 2.0의 차이점
    * HTTP/2 는 HTTP/1.1의 응답속도를 향상한 버전이다.
    * 멀티플렉싱
        * http 1.1에서 파이프라이닝 덕분에 단일 커넥션상에서 여러 요청을 날릴수 있었다.
        * http 1.1의 파이프라이닝은 요청을 한꺼번에 해도 결국엔 응답은 순차적으로 받는 head of line blocking 문제가 발생했다.
        * http 2.0 에서는 이를 보완하여 응답도 개별적으로 처리되어 지연이 없게 됨
* HTTP/2와 HTTP/3의 가장 큰 차이점은 HTTP/2 까지는 TCP위에서 동작하지만 3부터는 UDP위에서 동작한다는 것이다.

</div>
</details>


<details>
<summary><b>JWT란 ?</b></summary>
<div markdown="1">

* JWT란 ?
~~~
JWT (JSON Web Token)는 Json 포맷을 이용하여 사용자에 대한 속성을 저장하는 Claim 기반의 Web Token이다.
가볍고(compact) 자체적으로 필요한 정보를 담는(self-contained) 방식으로, 
서버와 클라이언트 사이에서 JSON 객체를 빠르고 안전하게 전달한다.
~~~

</div>
</details>


<details>
<summary><b>REST, RESTful, REST API ?</b></summary>
<div markdown="1">

#### REST 란
> Representational State Transfer
~~~
간단하게 설명하자면, REST는 URI를 통해 자원을 명시하고
HTTP Method(POST, GET, PUT, DELETE)를 통해 해당 자원에 대한 CRUD Operation을 적용하는 것을 의미한다.
~~~
* 클라이언트와 서버의 통신 방식
* URI와 HTTP를 이용한, 통신 목적의 **아키텍처 스타일**(유형)
* 아키텍처 제작시 사용되는 가이드 정도의 의미로 사용되며 명확히 준수해야할 표준은 없다.

<br>

#### REST의 특징 (6가지 조건)
1. 일관된 인터페이스(Uniform interface)
    * URI 사용, HTTP 메소드 사용, RPC미호출 등의 **지정된 인터페이스**를 준수한다.

2. 클라이언트/서버 구조
    * 클라이언트는 서버에 요청 메시지를 전송하고
    * 서버는 요청에 대한 응답 메시지를 전송한다.

3. 무상태(stateless) - `Cookie&Session파일 참고`
    * 세션등 이전 상황(문맥) 없이도 통신할 수 있다.

4. 캐시가능(Cacheable)
    * 서버의 응답 메시지는 캐싱될 수 있다.

5. 계층화된 시스템(Layered system)
    * 계층별로 기능이 분리된다.
    * Client는 REST API Server만 호출한다.
    * 따라서 중간 계층의 기능(로드밸런싱, 서버증설, 인증 시스템 도입 등)이 변경되어도 통신에 영향이 없다.

6. 주문형 코드(code on demand)
    * 반드시 충족할 필요는 없는 조건이다.
    * 손쉬운 데이터 처리를 위해 서버는 클라이언트에서 실행될 스크립트를 전송할 수 있다.


<br>

#### Rest API
* REST 기반으로 서비스 API를 구현한것

<br>

#### RESTful
* REST를 따르는 시스템을 RESTful하다 라고 함
* REST API를 제공하는 웹 서비스를 RESTful하다고 할 수 있다.

</div>
</details>