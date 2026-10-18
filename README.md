# unit-tests-lab-3



Марченко Владислав, група З-41

Номер у журналі: 25

Варіант: 5

Мова: C++



Проєкт збирається через CMake (файл CMakeLists.txt). Бібліотека GoogleTest завантажується автоматично під час налаштування проєкту.



\## Як запустити тести

Відкрити папку в Visual Studio і зібрати проєкт. Далі відкрити файл tests/test\_late\_fee.cpp і  запустити.



\## Як отримати покриття

Покриття вимірюється програмою OpenCppCoverage:

OpenCppCoverage --sources late\_fee.cpp --excluded\_sources test\_late\_fee.cpp --export\_type html:coverage -- out\\build\\x64-Debug\\late\_fee\_tests.exe

Звіт зберігається в папці coverage (файл coverage/index.html).



\## Фактичний відсоток покриття

100% рядків модуля late\_fee.cpp (9 рядків, непокритих немає).

