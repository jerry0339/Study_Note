# 알고리즘 PS Note
* 알고리즘문제 풀면서 새로 알게된 Java문법 & 해결 전략
* [참고중인 링크](https://wonit.tistory.com/)


******************************************************
### 0. BufferedReader와 BufferedWriter 그리고 StringTokenizer
Java로 알고리즘 PS를 할때, 입출력으로 Scanner와 System.out.println 대신
**BufferedReader**와 **BufferedWriter**를 사용해야 함.
가장 빠르기 때문

파싱할때는 split대신 **StringTokenizer**를 사용해야 함



<br>

******************************************************
### 1. 데이터 입력받기
입력은 Scanner 보다 BufferedReader가 더 빠름

* Scanner를 이용한 입력
~~~java
Scanner sc = new Scanner(System.in);
String str = sc.nextLine(); // 1 2 3 4 5 6 7 8 9 10
String[] result = str.split(" ");
~~~

* BufferedReader를 이용한 입력
readLine()을 통해 한줄씩 읽어 올 수 있음 (개행 기준)
~~~java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
String[] result = br.readLine().split(" ");
~~~

BufferedReader가 **문자열에 최적화** 되어 있기 때문에 더 빠름
대신 Scanner는 BufferedReader보다 더 **다양한 기능 제공**

<br>

******************************************************
### 2. split VS StringTokenizer

* split : String Class의 메소드
`str.split("." | "," | "+");` 와 같이 여러개의 구분자 지정가능
~~~java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
String[] result = br.readLine().split(" ");

// 1 Q 2 W 입력시
result[0]; // "1"
result[1]; // "Q"
result[3]; // "2"
result[4]; // "W"
~~~

* StringTokenizer : 클래스
구분자를 생략하면 **공백**이 기본 구분자
지정한 **한가지** 구분자로만 **문자열**을 나눌 수 있음
`nextToken()`으로 구분된 데이터를 문자열로 출력
~~~java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
StringTokenizer st = new StringTokenizer(br.readLine()); // 아래처럼 구분자(" ")가 생략되어 있음
// StringTokenizer st = new StringTokenizer(br.readLine(), " "); 

/* 아래의 데이터 입력시
1 Q 2 W 
3 E 4 R
*/
String a = st.nextToken(); // "1"
String b = st.nextToken(); // "Q"
String c = st.nextToken(); // "2"
String d = st.nextToken(); // "W"

// 개행이 있으므로 
st = new StringTokenizer(br.readLine());
String e = st.nextToken(); // "3"
String f = st.nextToken(); // "E"
String g = st.nextToken(); // "4"
String h = st.nextToken(); // "R"
~~~



<br>

******************************************************
### 3. 출력

~~~java
int dx[] = {1,0,-1,0};

System.out.println(dx[0]+dx[1]+dx[2]+dx[3]); // 0 출력 
System.out.println(dx[0]+" "+dx[1]+" "+dx[2]+" "+dx[3]); // 1 0 -1 0 출력
~~~


<br>

******************************************************
### 4. 강제종료
* `System.exit(0);` 쓰면 됨


<br>

******************************************************
### 5. 클래스 생성과 정렬

~~~java
int N = 10;
Student[] stu = new Student[N];
for(int i=0; i<N; i++){
    int sum = 0;
    st = new StringTokenizer(br.readLine());
    str = st.nextToken();
    a = Integer.parseInt(st.nextToken());
    b = Integer.parseInt(st.nextToken());
    c = Integer.parseInt(st.nextToken());
    sum = c*10000 + b*100 + a;
    stu[i] = new Student(sum, str);
}

Arrays.sort(stu, new Comparator<Student>() {
    @Override
    public int compare(Student a, Student b) {
        return Integer.compare(a.birth, b.birth);
    }
});

System.out.println(stu[N-1].name);
System.out.println(stu[0].name);

//---------------------------------------------------

class Student {
    public int birth;
    public String name;

    public Student(int birth, String name){
        this.birth = birth;
        this.name = name;
    }
}
~~~




<br>

******************************************************
### 6. 정렬
primitive type 배열은 Dual Pivot Quick Sort를 하고 nlogn 을 기대할 수 있지만, 최악의 경우 n^2.
primitive type은 comaprator를 지정할 수 없음.
객체, 제네릭 타입들은 comparator를 지정하여 사용하고,
Merge sort 또는 TimSort가 수행됨. 이는 최악의 경우에도 nlogn을 기대할 수 있음.

Dual Pivot Quick Sort의 경우
평균적인 연산량을 더 줄여내도록 만든 퀵소트의 변형 중 하나임
자세한건 구글링

Arrays.sort()의 경우 O(Nlog(N))을 보장하지 못하므로
java.util의 Collections.sort를 사용하는것이 좋음 -> O(Nlog(N)) 보장
Collections.sort를 사용하기 위해서는 **ArrayList**를 사용해야 함

sort할때 c++은 true false기준으로 정렬했다면
java는 음수, 0, 1 기준으로 정렬

* 정렬 예시
~~~java
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {

        ArrayList<Oiis> arr = new ArrayList<>();

        for(int i=0; i<20; i++){
            arr.add(new Oiis((int)(Math.random()*10), (int)(Math.random()*10), "123"));
        }
        
        Collections.sort(arr, (fir, sec) -> {
            if(fir.a == sec.a) return fir.b - sec.b;
            return fir.a - sec.a;
        });

        for (Oiis next : arr) {
            System.out.println(next.a +" "+next.b+" "+next.str);
        }

    }
    static class Oiis{ // Object int, int, string
        int a;
        int b;
        String str;

        public Oiis(int a, int b, String str) {
            this.a = a;
            this.b = b;
            this.str = str;
        }
    }
}
~~~


<br>

******************************************************
### 7. Collections 클래스
**주의!** : Collections 클래스는 Collection클래스와는 다른 클래스임
정적 메소드만으로 구성되어 있음
알고리즘PS에 필요없는 메소드들은 제외함

1. max, min : 컬렉션에서 최대, 최소를 반환 (인덱스X)
2. sort : 위에서 설명함
3. binarySearch : 이분탐색으로 지정된 객체를 검색해 인덱스를 반환
4. copy : 컬렉션 복사, 새로운 컬렉션 반환
5. reverse : 지정된 컬렉션의 순서를 반대로 변경
6. reverseOrder : 내림차순으로 바꿔줌

* **reverseOrder**
사용예시
~~~java
TreeSet<String> set = new TreeSet<>(Collections.reverseOrder());
~~~

* **binarySearch**
key가 list에 없을시 (-1*pos -1)이 lower_bound위치임
사용예시
~~~java
int pos = Collections.binarySearch(list, key);
~~~




<br>

******************************************************
### 8. 자료구조 정리
1. List인터페이스의 ArrayList
대량의 자료를 추가/삭제시 복사가 일어 나게 되어 성능 저하, non-thread-safe
add : O(1)
remove : O(n)
get : O(1)
Contains : O(n)
iterator.remove : O(n)

2. Set인터페이스의 TreeSet, TreeMap
레드블랙트리임
add : O(logN)
remove : O(logN)
next : O(logN)

* TreeMap 생성
~~~java
Map<Oiis, Integer> map = new TreeMap<>(Comparator.reverseOrder());
~~~

List Set Map Queue 인터페이스 사용해 본 후 Note 업데이트 예정
[참고링크](https://unordinarydays.tistory.com/194)



<br>

******************************************************
### 9. Java Arrays.fill
C++의 memset과 같은 기능

* 사용예시
~~~java
int[][] arr2 = new int[5][5];  
for(int[] arr1 : arr2) 
    Arrays.fill(arr1, 1);
~~~


<br>

******************************************************
### 10. 출력할 문자열이 많을때, 빠른 출력
출력해야할 문자열이 많다면 아래와 같은 방법을 사용하면 빠른 시간안에 출력이 가능함
~~~java
TreeSet<String> set = new TreeSet<>();
//....
StringBuilder sb = new StringBuilder();
for (String s : set) {
    sb.append(s);
    sb.append("\n");
}
System.out.println(sb.toString());
~~~


<br>



******************************************************
### 11. String 함수
* charAt
C++과는 다르게 str[i] 대신 str.charAt(i)로 함수를 사용

* substring
C++의 substr(start_Idx, length) 였다면,
java는
substring(length) : 0부터 length-1까지의 substring
substring(start_Idx, end_Idx)

* 업뎃 예정


<br>

******************************************************
### 12. reverse()
* 문자열을 reverse하고 싶다면?
~~~java
StringBuilder sb = new StringBuilder(a);
a = sb.reverse().toString();
// 또는 StringBuilder그대로 사용하기
~~~

* 리스트를 reverse하고 싶다면?
Collections.reverse() 를 이용
단, ArrayList이용해야 함



<br>

******************************************************
### 13. String.format()
서식형을 이용하여 문자열을 만들어 낼 수 있음
C언어와 서식형이 다르지 않음. ex) %d, %c, %s
[참고링크](https://blog.jiniworld.me/68)

* Integer formating 예시
~~~java
int i = 123456789;

System.out.println(String.format("%,d_", i));
System.out.println(String.format("%,15d_", i));
System.out.println(String.format("%,-15d_", i));
System.out.println(String.format("%,015d_", i));

/*
출력결과
123,456,789_
    123,456,789_
123,456,789    _
0000123,456,789_
*/

~~~



<br>

******************************************************
### 14. Optional
> [참고](https://engkimbs.tistory.com/646)
> reference타입 -> null이 될 수 있음 -> NullpointerException을 일으킴
> Optional을 이용하여 null을 사용하지 않고 해결

**Optioanl을 이용한 null데이터**
* null 데이터 : `Optional.empty()` 대입
* null아닌 데이터 : `Optional.of(객체)` 대입

* null인지 아닌지 확인하기
~~~java
test = Optional.of(new User(123L));
bool chk1 = test.isEmpty();  // test에 값이 없으면 true
bool chk2 = test.isPresent(); // test에 값이 있으면 true
~~~

* optional의 **get()은 사용하면 안됨!!!** -> null을 감싼것을 다시 풀기 때문에 optional을 사용한 의미가 없어짐
> filter(), map() 과 같은 메소드로 조건을 확인하고
> orElse(), orElseGet(), orElseThrow()로 결과 반환 하는 과정을 거쳐야 함

* of()와 ofNullable()의 차이점
자바에서 제공하는 객체를 Optional 객체로 감싸기 위해서는 Optional 에서 제공하는 of 와 ofNullable 매서드를 사용합니다.
둘의 차이점은 **of**는 인자로서 **null값을 받지 않는다는 것**이고 **ofNullable**은 **null값을 허용**한다는 것입니다.
즉, of()메소드로 null값을 입력받을시 NPE를 일으킴

* of() 와 ofNullable() 중 어느것을 사용해야 할까 ?
[참고](http://daplus.net/java-optional-ofnullable%EB%B3%B4%EB%8B%A4-optional-of%EB%A5%BC-%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94-%EC%9D%B4%EC%9C%A0%EB%8A%94-%EB%AC%B4%EC%97%87%EC%9E%85%EB%8B%88%EA%B9%8C/)



<br><br>

******************************************************
### 15. 문자열 비교 (NULL 관련)
`변수.equals("문자")`, `"문자".equals(변수)` 중 어떤것이 더 좋은 방법일까 ?
`변수.equals("문자")` 에서 변수에 Null이오면 NullPointerException이 날 수 있음
따라서 `"문자".equals(변수)`로 문자열을 비교하는것이 옳다.




<br>

******************************************************
### 16. Queue 사용 예시
BOJ_21736 코드

~~~java
import java.io.*;
import java.util.*;

public class Main{
    static int N,M;
    static char[][] m;
    static int sty=0, stx=0;
    static int[] dy = {-1,1,0,0};
    static int[] dx = {0,0,-1,1};
    static boolean[][] vi;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        m = new char[N][M];
        vi = new boolean[N][M];
        for(int i=0; i<N; i++){
            m[i] = br.readLine().toCharArray();
            for(int j=0; j<M; j++){
                if('I' == m[i][j]){
                    sty = i;
                    stx = j;
                }
            }
        }

        int ans = bfs();
        if(ans==0) bw.write("TT");
        else bw.write(ans+"");
        bw.flush();
        bw.close();
        br.close();
    }

    static int bfs(){
        int ret = 0;
        Queue<Point> q = new LinkedList<>();
        q.add(new Point(sty,stx));

        while(!q.isEmpty()){
            Point pt = q.poll();
            int cy = pt.y;
            int cx = pt.x;
            for(int i=0; i<4; i++){
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if(ny<0 || nx<0 || ny>=N || nx>=M || vi[ny][nx] || 'X' == m[ny][nx]) continue;
                if('P' == m[ny][nx]) ret++;
                q.add(new Point(ny,nx));
                vi[ny][nx] = true;
            }
        }

        return ret;
    }

    static class Point{
        int y=0;
        int x=0;

        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}

~~~



<br>

******************************************************
### 18. BufferedReader, BufferedWriter, StringTokenizer 다시 정리
예시로 익히기

~~~java
int N,M;
char[][] m; // char 이차원 배열일 경우
int sty=0, stx=0;

BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
StringTokenizer st = new StringTokenizer(br.readLine());
N = Integer.parseInt(st.nextToken());
M = Integer.parseInt(st.nextToken());

m = new char[N][M];
for(int i=0; i<N; i++){
    m[i] = br.readLine().toCharArray(); // toCharArray로 배열로 받아올 수 있음
    for(int j=0; j<M; j++){
        if('I' == m[i][j]){
            sty = i;
            stx = j;
        }
    }
}
~~~



<br>

******************************************************
### 19. Queue의 구현체
LinkedList vs ArrayDeque 어느것이 더 효율적일까 ?
결론만 말하자면 ArrayDeque가 더 효율적이다.
그 이유는 ? 
1. 더 **빠르다**.
2. 리스트와 비교해서 추가 참조가 필요없으므로 **메모리** 효율이 좋다

[참고링크](https://chucoding.tistory.com/52)




<br>

******************************************************
### 20. equals()와 HashCode()의 오버라이딩
논리적 동등비교를 위해 equals를 오버라이딩 해야 한다면
equals()와 hashCode() 둘 모두를 오버라이딩 해야 함
equals()로 객체를 비교하면 아래와 같은 과정을 거침
![](2021-09-05-17-47-03.png)

#### 재정의를 하지 않으면 생기는 문제점
같은 값을 가진 객체가 서로 다른 해시값을 갖게 될 수 있다.
특히 HashSet, HashMap, HashTable의 key 값으로 해당 객체를 사용할 경우 문제가 발생한다.



#### Object클래스의 equals() 규약
* equals 메서드는 null이 아닌 개체 참조에 대해 동등성 관계를 구현
1. reflexive(재귀의) : 자기 자신과의 비교에서 항상 true를 return한다. x.equals(x) == true
2. symmetric(대칭적인) : x.equals(y) = y.equals(x) =true (교환 법칙)
3. transitive(전이하는) : x.equals(y) = y.equals(z) 이면  x.equals(z) (추이 법칙)
4. consistent(일관된) : 반복된 비교에도 일관된 결과를 반환 -> 멱등성(idempotent)에 관한 설명
5. Null과의 equals 비교는 항상 false 출력



#### Object클래스의 hashCode() 규약
1. hashCode 메서드는 몇 번을 호출해도 항상 같은 값을 반환
2. equals(Object)가 두 객체를 같다고 판단했으면, 두 객체의 hashCode 값은 항상 같아야 함
3. 하지만 equals(Object)가 두 객체를 다르다고 판단했더라도, 두 객채의 hashCode 값은 같을 수 있다. (해시 충돌)




<br><br>

******************************************************
### 21. Object클래스의 hashCode() 규약


hashCode 메서드는 몇 번을 호출해도 항상 같은 값을 반환
equals(Object)가 두 객체를 같다고 판단했으면, 두 객체의 hashCode 값은 항상 같아야 함
하지만 equals(Object)가 두 객체를 다르다고 판단했더라도, 두 객채의 hashCode 값은 같을 수 있다. (해시 충돌)

재정의를 하지 않으면 생기는 문제점
같은 값을 가진 객체가 서로 다른 해시값을 갖게 될 수 있다.
특히 HashMap의 key 값으로 해당 객체를 사용할 경우 문제가 발생한다.

<br><br>

******************************************************
### 22. 이중괄호를 이용한 초기화
[이중괄호를 사용하면 안되는 이유](https://m.blog.naver.com/sthwin/221966310324)
가독성이 좋고 짧지만, 잘 알려지지 않은 방식이다.
메모리 누수가 생길 수 있다.

대안
1. 컬렉션의 .of() 메소드를 사용한다
Null이 올 수 없으므로 Null값이 올 수 있으면 사용하지 말아야 함
2. 기존 방식으로 초기화 한다.




<br><br>

******************************************************
### 23. static
1. 어떤 클래스에서 인스턴스를 매번 생성할때마다 꼭 필요한 멤버(필드 or 메소드)가 아니라면
해당 멤버를 static으로 선언해 주는것은 좋은 방법




<br><br>

******************************************************
### 24. final 메소드, 클래스
* final 클래스
final이 붙은 클래스는 상속을 금지시킴
즉, 다른 클래스에서 final이 붙은 클래스를 상속할 수 없다는 뜻

* final 메소드
해당 메소드의 오버라이딩을 금지시킴
서브클래스가 슈퍼클래스의 final 메소드를 오버라이딩 할 수 없다는 뜻




<br><br>

******************************************************
### 25.




<br><br>

******************************************************
### 26.




<br><br>

******************************************************
### 27.



<br><br>

******************************************************
### 27.



<br><br>
******************************************************
### 27.



<br><br>
******************************************************
### 27.



<br><br>