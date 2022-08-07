# Git

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