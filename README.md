# CP | СП
Competitive programming | Спортивное программирование

Начало - 09.2019

```
g++ -Winvalid-pch -x c++-header -o ./stdc++.h.gch -std=c++20 /usr/include/c++/$(g++ --version | head -n 1 | grep -oP '[0-9.]+(?= )')/x86_64-pc-linux-gnu/bits/stdc++.h
g++ -Winvalid-pch -x c++-header -o ./stdc++.h.g.gch -std=c++20 -g /usr/include/c++/$(g++ --version | head -n 1 | grep -oP '[0-9.]+(?= )')/x86_64-pc-linux-gnu/bits/stdc++.h
g++ -I ~/CP -include stdc++.h -DLOCAL -std=c++20 A.cpp
g++ -I ~/CP -include stdc++.h.g -DLOCAL -std=c++20 -g A.cpp

make -sf ~/CP/Makefile F=G.cpp
```
