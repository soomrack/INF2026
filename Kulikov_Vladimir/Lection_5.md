# Информатика — Лекция 05: Объектно-ориентированное программирование (весна 2026)

**Преподаватель:** к.ф.-м.н. Михаил Сергеевич Ананьевский

---

## 1) ООП: что это и откуда появилось

**ООП (объектно-ориентированное программирование)**:
- появление — **конец 1950-х** (в контексте развития ИИ, язык **Lisp**);
- становление — **вторая половина 1960-х** (первые ООП-языки: **Simula**, **Smalltalk**).

**Объектно-ориентированный язык** — язык программирования, который соответствует концепциям объектно-ориентированного программирования.  
(ГОСТ 33707–2016)

---

## 2) Термины (по ISO/IEC 2382:2015)

- **object** — набор операций и данных, которые сохраняют эффект этих операций.
- **object language** — целевой язык для выражения объектных программ.
- **object-oriented** — относящийся к технике или языку программирования, который поддерживает **объекты, классы и наследование**.
- **object-oriented language** — язык программирования, который поддерживает объектно-ориентированные концепции.

---

## 3) Класс, наследование, полиморфизм

### Класс
- **class** — шаблон для объектов, который определяет внутреннюю структуру и набор операций для экземпляров.
- **класс** — описание множества объектов, для которых есть одни и те же атрибуты, операции, методы, взаимосвязи и семантика.  
(ISO/IEC 2382:2015; ГОСТ 33707–2016)

### Полиморфизм
- **polymorphism** — способность разных объектов по-разному реагировать на одно и то же сообщение.  
(ISO/IEC 2382:2015)

### Наследование
- **inheritance** — копирование всех или части внутренней структуры и набора операций из одного класса в подчинённый класс.  
(ISO/IEC 2382:2015)

---

## 4) Классы в C++: пример

```cpp
class Thermometer {
public:
  float temperature;
public:
  void get_temperature();
};

Thermometer top;
Thermometer bottom;

...

top.get_temperature();    // vs. get_temperature(top);
bottom.get_temperature(); // vs. get_temperature(bottom);
````

---

## 5) Доступ к полям класса (this-логика через метод)

```cpp
class Thermometer {
public:
  float temperature;
public:
  void get_temperature();
};

void Thermometer::get_temperature()
{
  temperature = dht.readTemperature();
  // vs. top.temperature = dht.readTemperature();
}
```

Идея: внутри метода мы работаем с полями **конкретного объекта** (как будто через `this->temperature`).

---

## 6) Инкапсуляция: сокрытие сложности

**Инкапсуляция** — принцип объединения данных и методов, работающих с этими данными, внутри одного класса и скрывающий детали реализации от внешнего мира.

---

## 7) Инкапсуляция в C (для сравнения)

**thermometer.h**

```c
struct Thermometer;
void get_temperature(struct Thermometer *thermometer);
```

**thermometer.c**

```c
struct Thermometer {
  ...
};

void get_temperature(struct Thermometer *thermometer)
{
  ...
}
```

---

## 8) Контроль доступа (private/public)

```cpp
class Bank {
private:
  int account; // доступ только через методы
public:
  void income_salary(int total); // тут можно учесть налоги
  int get_account() { return account; };
};

Bank my_vtb;

...

my_vtb.income_salary(180'000); // Correct
my_vtb.account += 180'000;     // Error
```

---

## 9) Дублирование кода и наследование

### Проблема: дублирование

```cpp
class ThermometerTested {
public:
  float temperature;
  bool is_broken;
public:
  void get_temperature();
  void run_self_test();
};
```

### Решение: наследование

```cpp
class ThermometerTested : Thermometer {
public:
  bool is_broken;
public:
  void run_self_test();
};

ThermometerTested top;

...

top.get_temperature();
top.runself_test();
```

---

## 10) Наследование и параметры функции

```cpp
void control_temperature(Thermometer thermometer)
{
  if (thermometer.temperature > 50) fan_start();
}

...

Thermometer top;
ThermometerTested bottom;

control_temperature(top);
control_temperature(bottom); // потому что наследование!
```

---

## 11) Наследование в C (и проблема приведения типов)

```c
struct Thermometer {
  int temperature;
};

struct ThermometerTested {
  int temperature;
  _Bool is_broken;
};

Thermometer top;
ThermometerTested bottom;
```

```c
void control_temperature(Thermometer *thermometer)
{
  if (thermometer->temperature > 50) fan_start();
}

control_temperature(*top);
control_temperature((Thermometer*)bottom);
```

**Проблема:** слабый контроль корректности приведения типов.

---

## 12) Open/Closed Principle (OCP)

**Open-Closed Principle (OCP):** сущности ПО (классы, модули, функции и т.д.) должны быть:

* **открыты для расширения**
* **закрыты для модификации**

Грубо: хочешь расширить функциональность — **создавай наследников**, а не переписывай базовые классы.

---

## 13) Конструкторы

```cpp
class Bank {
public:
  int account;
public:
  Bank() { account = 0; };
  Bank(int account) : account(account) {};
};

int main()
{
  Bank my_vtb();
  Bank my_alfa(3'000);
}
```

---

## 14) Деструкторы

```cpp
class Bank {
public:
  int account;
  ~Bank() { account = 0; };
};

void proxy()
{
  Bank my_vtb();
  my_vtb.account += 100'000;
}

int main()
{
  proxy();
}
```

Идея: деструктор вызывается при выходе объекта из области видимости.

---

## 15) RAII

**RAII (Resource Acquisition Is Initialization)** — принцип ООП, который привязывает ресурс ко времени жизни объекта.

Пример:

```cpp
class Heap {
private:
  char* mem;
public:
  Heap(size_t size) { mem = malloc(size); };
  ~Heap() { free(mem); };
};

void job()
{
  Heap heap(1000);
  ...
} // нет утечки памяти!
```

---

## 16) Полиморфизм

### 16.1 Полиморфизм в параметрах (перегрузка)

```cpp
void print_temperature(Thermometer thermometer);
void print_temperature(ThermometerTested thermometer);

Thermometer top;
ThermometerTested bottom;

...

print_temperature(top);
print_temperature(bottom);
```

**Замечание:** какая функция вызовется — решается **при компиляции**.

---

### 16.2 Полиморфизм в методах (virtual / override)

```cpp
class Thermometer {
public:
  float temperature;
public:
  virtual void print_temperature();
};

class ThermometerTested : Thermometer {
public:
  float temperature;
public:
  virtual void print_temperature() override;
};
```

Реализация:

```cpp
void Thermometer::print_temperature()
{
  std::count << temperature << std::endl;
};

void ThermometerTested::print_temperature()
{
  std::count << temperature << " (tested)" << std::endl;
};
```

Вызов через ссылку на базовый класс:

```cpp
void print_climate(const Thermometer& thermometer)
{
  thermometer.print_temperature();
}

Thermometer top;
ThermometerTested bottom;

...

print_climate(top);    // 30
print_climate(bottom); // 30 (tested)
```

---

## 17) Позднее связывание

* **Полиморфизм в параметрах** (перегрузка) — какая функция будет вызвана, определяется **при компиляции**.
* **Полиморфизм в методах** (virtual) — какой метод будет вызван, определяется **во время выполнения** (позднее связывание).

---

## 18) Итог: ключевые аспекты ООП

Ключевые аспекты:

* **инкапсуляция**
* **наследование**
* **полиморфизм**

Задачи, которые решает ООП:

* сокрытие сложности (деталей реализации)
* уменьшение дублирования кода
* неявное выполнение кода



