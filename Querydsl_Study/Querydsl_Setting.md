# querydsl 설정
>  gradle 5 이상 버전에서의 세팅


### 1.  plugins에 추가
* ```
  id "com.ewerk.gradle.plugins.querydsl" version "1.0.10"
  ```

### 2. querydsl 버전 추가 
* build.gradle 첫줄에 추가
* ```
  buildscript {
     ext {
        queryDslVersion = "5.0.0"
     }
  }
  ```

### 3. Dependencies에 추가
* ```
  implementation "com.querydsl:querydsl-jpa:${queryDslVersion}"
  implementation "com.querydsl:querydsl-apt:${queryDslVersion}"
  ```

### 4. querydsl build process 설정정보 추가
* 아래의 코드는 **spring multi module** 사용시 세팅이 달라질 수 있음
* build.gradle 마지막줄에 추가
* ```
  def querydslDir = "$buildDir/generated/querydsl"
  
  querydsl {
     jpa = true
     querydslSourcesDir = querydslDir
  }
  sourceSets {
     main.java.srcDir querydslDir
  }
  compileQuerydsl{
     options.annotationProcessorPath = configurations.querydsl
  }
  configurations {
     compileOnly {
        extendsFrom annotationProcessor
     }
     querydsl.extendsFrom compileClasspath
  }
  ```

### 5. build.gradle refresh

### 6. 엔티티 작성

### 7. Q 타입 생성

* querydsl 컴파일러를 실행시켜 Q파일을 생성시킬 수 있음
  * Gradle - Tasks - build - clean 실행 (build 디렉토리 clean하는거라 초기에는 안해도 됨)
  * Gradle - Tasks - other - compileQuerydsl 실행

* 생성된 경로는 `4. querydsl build process 정보 추가` 에서 설정한 `querydslDir` 위치에 저장됨
* 생성된 Q파일은 Git에서 관리하면 안됨 (gitignore 이용)
  * 위의 설정을 그대로 이용하면 build폴더에 Q파일이 생성되기 때문에 ignore처리를 별도로 안해도 됨



















