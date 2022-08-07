# Git

<details>
<summary><b>git bash, git cmd 차이점</b></summary>
<div markdown="1">

* Git CMD는 git 의 일반적인 Windows 명령 프롬프트(cmd)와 같다
    - 명령. 명령 줄을 통해 모든 Git 기능을 사용할 수 있다
    - 이미 Windows cmd에 익숙하고 Windows에서만 작업하는 경우에 유용
* Git Bash는 창에서 bash 환경을 복제한다
    - 명령 행의 모든 ​​자식 기능과 대부분의 표준 유닉스 명령을 사용할 수 있다
    - Linux에 익숙하고 동일한 습관을 유지하려는 경우에 유용하다고 한다
    - 리눅스와 맥에서는 Bash가 기본 쉘임
    - 학습하기에는 bash를 사용하는 게 좋다.

</div>
</details>


<details>
<summary><b>git bash 기본 단축키, 명령어 정리</b></summary>
<div markdown="1">

* 단축키
    * Ctrl + Insert : 복사
    * Shift + Insert : 붙여넣기
    * Tab ⇆: 자동완성
    * Ctrl+C: 중단하기
    * Ctrl+L: 화면 지우기 (리눅스 clear와 동일)
    * Ctrl+T: 앞두글자 맞바꾸기
    * Ctrl+R: 이전 명령어 검색
    * Ctrl+X, Ctrl+V: bash 버전 표시
    * Ctrl+X, Ctrl+X: 이전 커서 위치(토글)
    * Ctrl+Z: 일시정지

<br>

* 명령어
    * ls : 현 디렉토리 내 파일과 디렉토리들 표시
    * pwd : 현재 작업중인 디렉토리 표시
    * cd : 디렉토리 이동
    * mkdir : 새로운 디렉토리 생성
    * touch : 새로운 파일 생성
       * touch keyboard.txt 라고하면 keyboard.txt라는 파일을 현 디렉토리 안에 생성함
    * cat : 파일 내용 표시
    * rm : 파일 삭제
        * rm -d : 디렉토리 삭제 (서브파일 있으면 삭제 불가)
        * rm -r : 디렉토리 삭제 (서브파일까지 무시하고 다 삭제)

</div>
</details>


<details>
<summary><b>Fork 한 Repository 업데이트 하기(git bash)</b></summary>
<div markdown="1">

1. clone할 디렉토리로 이동
    ~~~bash
    $ cd /c/Users/ChanuiJeon/Desktop/GitRepo
    ~~~
2. 로컬에 포크 저장소 clone
    ~~~bash
    $ git clone https://github.com/jerry0339/SJAlgorithm.git
    ~~~
3. clone한 디렉토리로 이동
    ~~~bash
    $ cd SJAlgorithm
    ~~~
4. 리모트 저장소 확인
    ~~~bash
    $ git remote -v
    origin  https://github.com/jerry0339/writeUp.git (fetch)
    origin  https://github.com/jerry0339/writeUp.git (push)
    ~~~
5. 리모트 저장소에 원본 저장소 추가
    ~~~bash
    $ git remote add upstream https://github.com/SJAlgorithm/SJAlgorithm.git
    ~~~
6. upstream으로 원본 저장소가 잘 추가되었는지 확인
    ~~~bash
    $ git remote -v
    origin  https://github.com/jerry0339/SJAlgorithm.git (fetch)
    origin  https://github.com/jerry0339/SJAlgorithm.git (push)
    upstream        https://github.com/SJAlgorithm/SJAlgorithm.git (fetch)
    upstream        https://github.com/SJAlgorithm/SJAlgorithm.git (push)
    ~~~
7. 원본 저장소 fetch
    ~~~bash
    $ git fetch upstream
    ~~~
8. 원본 저장소 merge
    ~~~bash
    $ git merge upstream/master
    ~~~
9. 포크 저장소로 push
    ~~~bash
    $ git push
    ~~~
10. Github에서 업데이트가 잘 되었는지 확인하기

</div>
</details>


<details>
<summary><b>Cherry-pick 이란?, 언제 사용할까 ?</b></summary>
<div markdown="1">

* [출처](https://zakelstorm.tistory.com/29)

## Cherry-pick 이란?
* 프로젝트 규모가 크고 많은 사람들이 코드를 수정하여 변화가 빈번하다면 rebase만으로는 한계가 있음
* cherry-pick이란, 다른 브랜치(feature) 위에 있는 커밋을 선택적으로 내 브랜치(main)에 적용시킬 때 사용하는 명령어

##  cherry-pick 필요한 상황 및 사용 이유
* 수정해야 할 commit이 다른 commit들 사이에 껴있는 경우, 수정 시 많은 reset을 필요로 할 경우에 cherry-pick을 활용하여 쉽게 해결할 수 있다.
* cherry-pick을 사용하면 좋은 경우 예시
    1. 커밋을 다른 브랜치에 잘 못했을 때 이를 뒤늦게 찾은 경우
    2. 요구사항이 바뀌어 필요없는 커밋이 생겼을 경우
        * 해당 커밋들을 빼고 cherry-pick
    3. 수정사항이 생겨 두개의 브랜치에 동시 commit 해야할 경우
        * 어느 한 브랜치에 커밋 후 다른 브랜치에서 cherry-pick
    4. 코드 의존성 때문에 다른 사람의 커밋 중 일부를 가져와야 할 경우

</div>
</details>

