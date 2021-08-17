# 알고리즘 PS Note
* 알고리즘문제 풀면서 새로 알게된 Java문법 & 해결 전략
* [참고중인 링크](https://wonit.tistory.com/)


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
    }
}

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
Primitive Type이 아닌 객체를 정렬할 때에는 아래와 같이 오버라이딩 하여 정렬할 수 있음

~~~java
class Student {
    public int birth;
    public String name;

    public Student(int birth, String name){
        this.birth = birth;
        this.name = name;
    }
}

//......
List<Student> stus = new ArrayList<Student>();
//......
Collections.sort(stus, new Comparator<Student>() {
    @Override
    public int compare(Student a, Student b) {
        return Integer.compare(a.birth, b.birth);
    }
});
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

* **binarySearch**
`int pos = Collections.binarySearch(list, key);` 와 같이 사용
key가 list에 없을시 (-1*pos -1)이 lower_bound위치



<br>

******************************************************
### 8. 자료구조 정리
1. List인터페이스의 ArrayList
add : O(1)
remove : O(n)
get : O(1)
Contains : O(n)
iterator.remove : O(n)
특징 : 대량의 자료를 추가/삭제시 복사가 일어 나게 되어 성능 저하, non-thread-safe

Set Map Queue 업데이트 예정