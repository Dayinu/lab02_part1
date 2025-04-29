## Домашнее задание 2

**Студентки группы ИУ8-22**

**Ивановой Влады**

<details>
<summary><h3>Part I</h3></summary>
<p>
1. Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).

https://github.com/Dayinulaba02
<hr>
2. Выполните инструкцию по созданию первого коммита на странице репозитория, созданного на предыдещем шаге.
 
```sh
$ echo "# lab02_part1" >> README.md
$ git init
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint:
hint:   git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint:   git branch -m <name>
Initialized empty Git repository in /home/linux/.git/
$ git add README.md
$ git commit -m "first commit"
[master (root-commit) 35ec349] first commit
 1 file changed, 3 insertions(+)
 create mode 100644 README.md
$ git branch -M main
$ ssh-keygen -t ed25519 -C vlada.privet@gmail.com
Generating public/private ed25519 key pair.
Enter file in which to save the key (/home/linux/.ssh/id_ed25519): 
Created directory '/home/linux/.ssh'.
Enter passphrase for "/home/linux/.ssh/id_ed25519" (empty for no passphrase): 
Enter same passphrase again: 
Your identification has been saved in /home/linux/.ssh/id_ed25519
Your public key has been saved in /home/linux/.ssh/id_ed25519.pub
The key fingerprint is:
"ssh ключ, который нельзя сообщать"
$ git remote set-url origin git@github.com:Dayinu/lab02_part1.git
$ git push -u origin main
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 234 bytes | 234.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Dayinu/lab02_part1.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.
```
 
<hr>
3. Создайте файл hello_world.cpp в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку using namespace std;.

```sh
cat << 'EOF' > hello_world.cpp
#include <iostream>
using namespace std;

int main(){
	cout << "Hello World";
	return 0;
}
EOF  
```
<hr>
4. Добавьте этот файл в локальную копию репозитория.
 
```sh
$ git add hello_world.cpp
```
<hr>
5. Закоммитьте изменения с осмысленным сообщением.
 
```sh
$ git commit -m "Добавлен hello_world.cpp с плохим стилем кода"
[main bc32f73] Добавлен hello_world.cpp с плохим стилем кода
 1 file changed, 7 insertions(+)
 create mode 100644 hello_world.cpp
```
<hr>
6. Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.
 
```sh
cat << 'EOF' > hello_world.cpp
#include <iostream>
using namespace std;

int main(){
        string name;
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"Hello world from "<<name;
        return 0;
}
EOF
```
<hr>
7. Закоммитьте новую версию программы. Почему не надо добавлять файл повторно git add?
 
```sh
$ git commit -a -m "Добавлен интерактивный ввод имени: теперь выводит 'Hello world from @name'"
[main eb94a8f] Добавлен интерактивный ввод имени: теперь выводит 'Hello world from @name'
 1 file changed, 5 insertions(+), 2 deletions(-)
```
<hr>
8. Запуште изменения в удалёный репозиторий.
 
```sh
$ git push origin main
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 2 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 888 bytes | 444.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Dayinu/lab02_part1.git
   35ec349..eb94a8f  main -> main
```
<hr>
9. Проверьте, что история коммитов доступна в удалёный репозитории.
 
```sh
$ git fetch origin && git log --remotes --oneline     
eb94a8f (HEAD -> main, origin/main) Добавлен интерактивный ввод имени: теперь выводит 'Hello world from @name'
bc32f73 Добавлен hello_world.cpp с плохим стилем кода
35ec349 first commit
                     
```
<hr>
</p>
</details>


 
<details>
<summary><h3>Part II</h3></summary>
<p>
1. В локальной копии репозитория создайте локальную ветку patch1.

```sh
$ git checkout -b patch1
Switched to a new branch 'patch1'
```
<hr>
2. Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.

```sh
$ cat << 'EOF' > hello_world.cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
EOF
```
<hr>
3. commit, push локальную ветку в удалённый репозиторий.
 
```sh
$ git add hello_world.cpp
$ git commit -m "Исправление: удалён using namespace std"                         
[patch1 78f27d3] Исправление: удалён using namespace std
 1 file changed, 7 insertions(+), 7 deletions(-)
$ git push -u origin patch1
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 463 bytes | 463.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
remote: 
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/Dayinu/lab02_part1/pull/new/patch1
remote: 
To github.com:Dayinu/lab02_part1.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.
```
<hr>
4. Проверьте, что ветка patch1 доступна в удалёный репозитории.

```sh
$ git fetch origin && git branch -r
  origin/main
  origin/patch1
```
<hr>
5. Создайте pull-request patch1 -> master.

[pull-request patch1 -> main](https://github.com/Dayinu/lab02_part1/pull/1)
<hr>
6. В локальной копии в ветке patch1 добавьте в исходный код комментарии.

```sh
$ nano hello_world.cpp
$ cat hello_world.cpp
#include <iostream>
#include <string>

// Главная функция программы
int main() {
    // Объявление переменной для хранения имени
    std::string name;
    
    // Запрос имени пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;
    
    // Вывод приветствия
    std::cout << "Hello world from " << name << std::endl;
    
    // Возврат успешного статуса выполнения
    return 0;
}
```
<hr>
7. commit, push.

```sh
$ git add hello_world.cpp
$ git commit -m "Добавлены поясняющие комментарии"                          
[patch1 2b5c318] Добавлены поясняющие комментарии
 1 file changed, 8 insertions(+)
$ git push origin patch1
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 660 bytes | 660.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
To github.com:Dayinu/lab02_part1.git
   78f27d3..2b5c318  patch1 -> patch1
```
<hr>
8. Проверьте, что новые изменения есть в созданном на шаге 5 pull-request

<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/0df304b3-9a69-497a-9f04-b02dce281ee1">
<hr>
9. В удалённый репозитории выполните слияние PR patch1 -> master и удалите ветку patch1 в удаленном репозитории.
<br>
<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/a65ffd6e-3d62-489a-873a-a0e65fa8bd0a">
<hr>

10. Локально выполните pull.

```sh
$ git checkout main
M	README.md
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
$ git pull origin main
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 904 bytes | 904.00 KiB/s, done.
From github.com:Dayinu/lab02_part1
 * branch            main       -> FETCH_HEAD
   5c6bcdb..2b5c318  main       -> origin/main
Updating 5c6bcdb..2b5c318
Fast-forward
 hello_world.cpp | 28 +++++++++++++---------------
 1 file changed, 13 insertions(+), 15 deletions(-)

```
<hr>
11. С помощью команды git log просмотрите историю в локальной версии ветки master.

```sh
$ git log
commit 2b5c3184f520b4e9dbe7b509e90e20ab7cdee45f (HEAD -> main, origin/main, patch1)
Author: Dayinu <vlada.privet@gmail.com>
Date:   Sun Apr 27 14:57:11 2025 -0400

    Добавлены поясняющие комментарии

commit 78f27d3c611b374fb3c17db257751464aefff2b3
Author: Dayinu <vlada.privet@gmail.com>
Date:   Sun Apr 27 14:24:32 2025 -0400

    Исправление: удалён using namespace std

commit eb94a8fe3a5c9d38272487c5f3655383535010b3
Author: Dayinu <vlada.privet@gmail.com>
Date:   Sun Apr 27 13:51:24 2025 -0400

    Добавлен интерактивный ввод имени: теперь выводит 'Hello world from @name'

commit bc32f730206c4d8d3b695906339f5260f1768085
Author: Dayinu <vlada.privet@gmail.com>
Date:   Sun Apr 27 13:44:14 2025 -0400

    Добавлен hello_world.cpp с плохим стилем кода

commit 35ec349e27fb6f0cc3a514dfef211590d6bff399
Author: Dayinu <vlada.privet@gmail.com>
Date:   Sun Apr 27 13:23:27 2025 -0400

    first commit

```
<hr>
12. Удалите локальную ветку patch1.

```sh
$ git checkout -b patch2
Switched to a new branch 'patch2'
```
<hr>
</p>
</details>
 
 <details>
<summary><h3>Part III</h3></summary>
<p>
1. Создайте новую локальную ветку patch2.

```sh
$ git checkout -b patch2
Switched to a new branch 'patch2'
```
<hr>
2. Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.

```sh
$ clang-format -i -style=Mozilla hello_world.cpp
Command 'clang-format' not found, but can be installed with:
sudo apt install clang-format
Do you want to install it? (N/y)y
sudo apt install clang-format
[sudo] password for linux: 
The following packages were automatically installed and are no longer required:
  libpython3.12-dev  python3.12  python3.12-dev  python3.12-minimal  python3.12-venv
Use 'sudo apt autoremove' to remove them.

Upgrading:
  clang  libc++1-19  libc++abi1-19  libllvm19  libunwind-19
                                                                                       
Installing:
  clang-format
                                                                                       
Installing dependencies:
  clang-19                libclang-cpp19      llvm-19               llvm-19-runtime
  clang-format-19         libclang-rt-19-dev  llvm-19-dev           llvm-19-tools      
  libclang-common-19-dev  libclang1-19        llvm-19-linker-tools                     
                                                                                       
Suggested packages:
  clang-19-doc  wasi-libc  llvm-19-doc

Summary:
  Upgrading: 5, Installing: 12, Removing: 0, Not Upgrading: 1406
  Download size: 114 MB
  Space needed: 611 MB / 12.9 GB available

Continue? [Y/n] y
Get:1 http://http.kali.org/kali kali-rolling/main amd64 libllvm19 amd64 1:19.1.7-1+b1 [26.0 MB]
Get:9 http://mirror.amuksa.com/kali kali-rolling/main amd64 clang-format amd64 1:19.0-63 [6,352 B]
Get:16 http://http.kali.org/kali kali-rolling/main amd64 llvm-19-tools amd64 1:19.1.7-1+b1 [511 kB]
Get:2 http://http.kali.org/kali kali-rolling/main amd64 libclang-cpp19 amd64 1:19.1.7-1+b1 [13.2 MB]
Get:3 http://http.kali.org/kali kali-rolling/main amd64 libclang-common-19-dev amd64 1:19.1.7-1+b1 [740 kB]
Get:4 http://http.kali.org/kali kali-rolling/main amd64 llvm-19-linker-tools amd64 1:19.1.7-1+b1 [1,261 kB]
Get:5 http://http.kali.org/kali kali-rolling/main amd64 libclang1-19 amd64 1:19.1.7-1+b1 [7,614 kB]
Get:6 http://http.kali.org/kali kali-rolling/main amd64 clang-19 amd64 1:19.1.7-1+b1 [116 kB]
Get:7 http://kali.download/kali kali-rolling/main amd64 clang amd64 1:19.0-63 [6,244 B]
Get:8 http://http.kali.org/kali kali-rolling/main amd64 clang-format-19 amd64 1:19.1.7-1+b1 [92.8 kB]
Get:10 http://http.kali.org/kali kali-rolling/main amd64 libunwind-19 amd64 1:19.1.7-1+b1 [63.0 kB]
Get:11 http://http.kali.org/kali kali-rolling/main amd64 libc++abi1-19 amd64 1:19.1.7-1+b1 [105 kB]
Get:12 http://http.kali.org/kali kali-rolling/main amd64 libc++1-19 amd64 1:19.1.7-1+b1 [303 kB]
Get:13 http://http.kali.org/kali kali-rolling/main amd64 libclang-rt-19-dev amd64 1:19.1.7-1+b1 [3,689 kB]
Get:14 http://http.kali.org/kali kali-rolling/main amd64 llvm-19-runtime amd64 1:19.1.7-1+b1 [551 kB]
Get:15 http://http.kali.org/kali kali-rolling/main amd64 llvm-19 amd64 1:19.1.7-1+b1 [16.4 MB]
Get:17 http://http.kali.org/kali kali-rolling/main amd64 llvm-19-dev amd64 1:19.1.7-1+b1 [43.2 MB]
Fetched 114 MB in 4min 21s (437 kB/s)                                                 
(Reading database ... 401495 files and directories currently installed.)
Preparing to unpack .../00-libllvm19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libllvm19:amd64 (1:19.1.7-1+b1) over (1:19.1.3-2) ...
Selecting previously unselected package libclang-cpp19.
Preparing to unpack .../01-libclang-cpp19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libclang-cpp19 (1:19.1.7-1+b1) ...
Selecting previously unselected package libclang-common-19-dev:amd64.
Preparing to unpack .../02-libclang-common-19-dev_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libclang-common-19-dev:amd64 (1:19.1.7-1+b1) ...
Selecting previously unselected package llvm-19-linker-tools.
Preparing to unpack .../03-llvm-19-linker-tools_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking llvm-19-linker-tools (1:19.1.7-1+b1) ...
Selecting previously unselected package libclang1-19.
Preparing to unpack .../04-libclang1-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libclang1-19 (1:19.1.7-1+b1) ...
Selecting previously unselected package clang-19.
Preparing to unpack .../05-clang-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking clang-19 (1:19.1.7-1+b1) ...
Preparing to unpack .../06-clang_1%3a19.0-63_amd64.deb ...
Unpacking clang (1:19.0-63) over (1:16.0-58.1) ...
Selecting previously unselected package clang-format-19.
Preparing to unpack .../07-clang-format-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking clang-format-19 (1:19.1.7-1+b1) ...
Selecting previously unselected package clang-format:amd64.
Preparing to unpack .../08-clang-format_1%3a19.0-63_amd64.deb ...
Unpacking clang-format:amd64 (1:19.0-63) ...
Preparing to unpack .../09-libunwind-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libunwind-19:amd64 (1:19.1.7-1+b1) over (1:19.1.3-2) ...
Preparing to unpack .../10-libc++abi1-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libc++abi1-19:amd64 (1:19.1.7-1+b1) over (1:19.1.3-2) ...
Preparing to unpack .../11-libc++1-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libc++1-19:amd64 (1:19.1.7-1+b1) over (1:19.1.3-2) ...
Selecting previously unselected package libclang-rt-19-dev:amd64.
Preparing to unpack .../12-libclang-rt-19-dev_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking libclang-rt-19-dev:amd64 (1:19.1.7-1+b1) ...
Selecting previously unselected package llvm-19-runtime.
Preparing to unpack .../13-llvm-19-runtime_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking llvm-19-runtime (1:19.1.7-1+b1) ...
Selecting previously unselected package llvm-19.
Preparing to unpack .../14-llvm-19_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking llvm-19 (1:19.1.7-1+b1) ...
Selecting previously unselected package llvm-19-tools.
Preparing to unpack .../15-llvm-19-tools_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking llvm-19-tools (1:19.1.7-1+b1) ...
Selecting previously unselected package llvm-19-dev.
Preparing to unpack .../16-llvm-19-dev_1%3a19.1.7-1+b1_amd64.deb ...
Unpacking llvm-19-dev (1:19.1.7-1+b1) ...
Setting up libllvm19:amd64 (1:19.1.7-1+b1) ...
Setting up libclang1-19 (1:19.1.7-1+b1) ...
Setting up libunwind-19:amd64 (1:19.1.7-1+b1) ...
Setting up libclang-common-19-dev:amd64 (1:19.1.7-1+b1) ...
Setting up libc++abi1-19:amd64 (1:19.1.7-1+b1) ...
Setting up libc++1-19:amd64 (1:19.1.7-1+b1) ...
Setting up libclang-rt-19-dev:amd64 (1:19.1.7-1+b1) ...
Setting up llvm-19-linker-tools (1:19.1.7-1+b1) ...
Setting up llvm-19-runtime (1:19.1.7-1+b1) ...
Setting up llvm-19-tools (1:19.1.7-1+b1) ...
Setting up libclang-cpp19 (1:19.1.7-1+b1) ...
Setting up clang-format-19 (1:19.1.7-1+b1) ...
Setting up clang-19 (1:19.1.7-1+b1) ...
Setting up clang (1:19.0-63) ...
Setting up llvm-19 (1:19.1.7-1+b1) ...
Setting up clang-format:amd64 (1:19.0-63) ...
Setting up llvm-19-dev (1:19.1.7-1+b1) ...
Processing triggers for libc-bin (2.40-3) ...
Processing triggers for systemd (256.6-1) ...
Processing triggers for man-db (2.13.0-1) ...
Processing triggers for kali-menu (2024.4.0) ...

```
<hr>
3. commit, push, создайте pull-request patch2 -> master.

```sh
$ git add hello_world.cpp 
$ git commit -m "Форматирование кода в стиле Mozilla с помощью clang-format"
[patch2 5c6bcdb] Форматирование кода в стиле Mozilla с помощью clang-format
 1 file changed, 15 insertions(+), 13 deletions(-)
$ git push -u origin patch2
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 466 bytes | 233.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote: 
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/Dayinu/lab02_part1/pull/new/patch2
remote: 
To github.com:Dayinu/lab02_part1.git
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'origin/patch2'.
```
<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/80b6e703-1ce8-4f90-b52d-d542cb67951d">
<hr>
4. В ветке master в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.

<br>
<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/a220635b-9285-47f2-bf2b-04fa199ca813">
<hr>
5. Убедитесь, что в pull-request появились конфликтны.
<br>
<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/0e1b457e-4d62-499f-b181-455c988806c4">
<hr>
6. Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.

```sh
$ git checkout main
$ git pull origin main
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 1.18 KiB | 1.18 MiB/s, done.
From github.com:Dayinu/lab02_part1
 * branch            main       -> FETCH_HEAD
   2b5c318..1fe049d  main       -> origin/main
Updating 2b5c318..1fe049d
Fast-forward
 hello_world.cpp | 10 +++++-----
 1 file changed, 5 insertions(+), 5 deletions(-)
$ git rebase main
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 5c6bcdb... Форматирование кода в стиле Mozilla с помощью clang-format
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
hint: Disable this message with "git config advice.mergeConflict false"
Could not apply 5c6bcdb... Форматирование кода в стиле Mozilla с помощью clang-format
$ nano hello_world.cpp
$ git add hello_world.cpp
$ git rebase --continue
[detached HEAD 8596614] Форматирование кода в стиле Mozilla с помощью clang-format
 1 file changed, 3 insertions(+), 1 deletion(-)
Successfully rebased and updated refs/heads/patch2.
```
<hr>
7. Сделайте force push в ветку patch2

```sh
$ git push origin patch2 --force
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 2 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 408 bytes | 408.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To github.com:Dayinu/lab02_part1.git
 + 5c6bcdb...8596614 patch2 -> patch2 (forced update)
```
<hr>
8. Убедитесь, что в pull-request пропали конфликтны.
<br>
<img width="50%" height="50%" src="https://gist.github.com/user-attachments/assets/227aeb38-5623-4866-91e9-f013344c3fae">

<hr>
9. Вмержите pull-request patch2 -> master.
 <br>
<img width="50%" height="50%" src="https://github.com/user-attachments/assets/be42c13f-5302-4879-a124-df4c180a461a">
</p>
</details>
