#include <stdio.h>


//|--------------------ТИПЫ ДАННЫХ-----------------------|

using RUB = long long int;      //тип данных для операций в рублях
using USD = long long int;      //тип данных для операций в долларах

using Percent = float;          //тип данных для процентов (1-100%)


//|--------------------СТРУКТУРЫ-----------------------|

struct Bank {                   //структура банка
    RUB account;
    RUB deposite;
    USD account_usd;
    float rate_usd_rub;

    Percent interest;
   
};


struct Car {                    //структура автомобиля
    RUB gas;
    RUB value;
};


struct Business {               //структура бизнеса
    RUB investment;      // инвестиции в бизнес 
    RUB monthly_profit;  // текущая прибыль (за месяц) (+/-)
    float risk_factor;   // риски (0.0 - 1.0)
};


struct Loan {                   //структура кредита
    RUB body;            // тело кредита
    Percent interest;    // процент по кредиту
    int months_left;     // сколько месяцев осталось платить
};


struct Person {                 //структура Персонажа (главная!!!)
    Bank zoobank;
    Car car;
    RUB salary;
    RUB food;

    //СЧЕТЧИКИ СТАТИСТИКИ

    int total_months;           //сколько месяцев прожито
    int food_payments_count;    //сколько раз покупала еду
    int gas_payments_count;     //сколько раз заправлялась
    int salary_payments_count;  //сколько зарплат получено
    int police_events_count;    //сколько событий на службе было
    int medicine_events_count;  //сколько раз лечилась
    RUB total_earned;           //общая сумма заработка
    RUB total_spent;            //общая сумма трат
};


struct NickPerson {      // отдельная структура для Персонажа Ник (главная!!!)
    Bank zoobank;
    Car car;             
    Business Nickizza;   // бизнес пиццы "никицца"
    Loan credit;         // долги банку/Джуди
    RUB food;
    RUB fines;           // штрафы от полиции
    
    //СЧЕТЧИКИ СТАТИСТИКИ

    int business_events_count;  //сколько событий в бизнесе
    int black_market_count;     //сколько раз был на черном рынке
    int rescue_events_count;    //сколько раз Джуди спасала
    int fines_count;            //сколько штрафов прилетело
    int loan_payments_count;    //сколько платежей по кредиту сделал
    RUB total_business_income;  //сколько принес бизнес всего
    RUB total_earned;           //общая сумма заработка
    RUB total_spent;            //общая сумма трат
};


struct Person judy;             //Создание Персонажа Джуди;
struct NickPerson nick;             //Создание Персонажа Ник;


struct Wedding {         //структура СВАДЬБЫ
    RUB budget;          //общие накопления
    RUB cafe_rent;       //аренда кафе 
    RUB travel_cost;     //медовый месяц на острове
    RUB rings_cost;      //кольца с морковкой и лисом
    int guests_count;    //количество гостей (вся полиция и мафия)
    bool is_possible;    //хватает ли денег?
};


struct Wedding wedding;     //свадьба Ника и Джуди


//|--------------------ФУНКЦИИ-----------------------|

float key_rate(const int month, const int year);    //чтобы писать функции в любом порядке
float delta(const int month, const int year);


void judy_init()                            //функция инициализации Джуди
{
    //банковские счета
    judy.zoobank.account = 0;
    judy.zoobank.deposite = 1'000'000;
    judy.zoobank.interest=12.0;
    judy.salary = 180'000;

    judy.zoobank.account_usd = 1'000;
    judy.zoobank.rate_usd_rub = 78.5;

    //расходы на еду
    judy.food = 20'000;

    //машина (хорошая)
    judy.car.value = 2'400'000;
    judy.car.gas = 15'000;

    //счётчики
    judy.total_months = 0;
    judy.food_payments_count = 0;
    judy.total_earned = 0;
    judy.total_spent = 0;
    judy.gas_payments_count = 0;
    judy.salary_payments_count = 0;
    judy.police_events_count = 0;
    judy.medicine_events_count = 0;

}


void nick_init()
{
    //банковские счета
    nick.zoobank.account = 90'000;
    nick.zoobank.deposite = 0;
    nick.zoobank.interest = 0;

    nick.zoobank.rate_usd_rub = 78.5;

    //штрафы
    nick.fines = 0;

    //машина (старая развалюха)
    nick.car.value = 400'000;
    nick.car.gas = 10'000;

    //расходы на еду
    nick.food = 15'000;

    //бизнес "Никицца"
    nick.Nickizza.investment = 200'000;
    nick.Nickizza.monthly_profit = 50'000;       //базовая прибыль
    nick.Nickizza.risk_factor = 0.3;             //30% шанс на неудачу

    //кредит (на бизнес)
    nick.credit.body = 600'000;
    nick.credit.interest = 18.0;         //высокий процент по кредиту (18%)
    nick.credit.months_left = 36;        //кредит на 3 года

    //счетчики
    nick.business_events_count = 0;  //сколько событий в бизнесе
    nick.black_market_count = 0;     //сколько раз был на черном рынке
    nick.rescue_events_count = 0;    //сколько раз Джуди спасала
    nick.fines_count = 0;            //сколько штрафов прилетело
    nick.loan_payments_count = 0;    //сколько платежей по кредиту сделал
    nick.total_business_income = 0  ;  //сколько принес бизнес всего
    nick.total_earned = 0;           //общая сумма заработка
    nick.total_spent = 0;            //общая сумма трат
}


void inflation(const int month, const int year)        //функция инфляции
{
    //индексация в первом месяце года
    if (month == 1) {
        float rate = key_rate(month, year);
        float multiplier = (rate + 100.0) / 100.0;

        judy.salary = (RUB)(judy.salary * multiplier);          //увеличение зарплаты на ставку (индексация)
        judy.food = (RUB)(judy.food * multiplier);
        judy.car.gas = (RUB)(judy.car.gas * multiplier);

        judy.car.value = (RUB)(judy.car.value * 0.95);          //уменьшение стоимости машины Джуди


        nick.food = (RUB)(nick.food * multiplier);
        nick.car.gas = (RUB)(nick.car.gas * multiplier);
        nick.Nickizza.monthly_profit = (RUB)(nick.Nickizza.monthly_profit * multiplier);      //цены на пиццу растут со временем
        nick.car.value = (RUB)(nick.car.value * 0.90);          //уменьшение стоимости машины Ника (стареет быстрее чем у Джуди)
    }
}


void calculate_taxes(int year) {                        //ПЛОТИ НОЛОГИ!!!
    printf("\n\n--- NALOGOVAYA INSPEKCIYA ZVEROPOLISA (GOD %d) ---\n", year);

    RUB judy_car_tax = (RUB)(judy.car.value * 0.02);        //налог на машину Джуди, зависящий от стоимости
    judy.zoobank.account -= judy_car_tax;
    judy.total_spent += judy_car_tax;
    printf("Judy zaplatila nalog na avto: %lld RUB\n", judy_car_tax);


    RUB nick_business_tax = (RUB)(nick.Nickizza.investment * 0.05);      //налог на бизнес Ника
    nick.zoobank.account -= nick_business_tax;
    printf("Nick zaplatil nalog na biznes: %lld RUB\n", nick_business_tax);

    
    if (nick.zoobank.account < 0) {         //штраф за незаконную торговлю (если Ник в минусе)
        nick.fines += 20000;
        nick.fines_count++;
        printf("Nick poluchil dopolnitel'nyy shtraf za dolgi.\n");
    }
    printf("--------------------------------------------------\n\n");
}


void update_currency_rate(int month, int year)          //обновление курса валюты
{            
    float base_rate = 78.5;         // Базовый курс зависит от года (тренд на рост)
    if (year == 2027) base_rate = 82.0;
    if (year == 2028) base_rate = 89.5;
    if (year == 2029) base_rate = 95.0;
    if (year == 2030) base_rate = 96.5;
    if (year == 2031) base_rate = 93.0;

    //"случайное" колебание месяца
    float colebaniye = ((month * 13 + year) % 11) - 5; //колебание от -5 до +5 рублей

    judy.zoobank.rate_usd_rub = base_rate + colebaniye;
    nick.zoobank.rate_usd_rub = judy.zoobank.rate_usd_rub; // У Ника тот же курс в базе

    printf("  [EXCHANGE MARKET]: Kurs dollara: %.2f RUB\n\n", judy.zoobank.rate_usd_rub);
}


//НИК

void nick_business_logic(const int month, const int year)         //Ник зарабатывает на пицце
{
    nick.zoobank.account += nick.Nickizza.monthly_profit;
    nick.total_business_income += nick.Nickizza.monthly_profit;     //счетчик прибыли
    nick.business_events_count++;       //счетчик рабочих смен
    nick.total_earned += nick.Nickizza.monthly_profit;
}

void nick_loan_payment()            //платежи Ника по кредиту
{   
    if (nick.credit.months_left > 0 && nick.credit.body > 0) {          //проверка, есть ли еще долг и остались ли месяцы
        
        RUB principal_payment = nick.credit.body / nick.credit.months_left;             //подсчет, какую часть основного долга гасит в этом месяце
        RUB interest_payment = (RUB)(nick.credit.body * (nick.credit.interest / 100.0 / 12.0));//       подсчет процентов, которые банк забирает себе "в карман"
        RUB total_monthly_payment = principal_payment + interest_payment;           //общий платеж, который Ник отдает в банк

        
        nick.zoobank.account -= total_monthly_payment;          //списывание денег у Ника
        nick.total_spent += total_monthly_payment;          //счетчик заработка
        nick.loan_payments_count++;                     //счетчик = плюс один успешный платеж
        nick.credit.body -= principal_payment;                  //уменьшение самого долга перед банком
        nick.credit.months_left--;              //уменьшение количества оставшихся месяцев

        if (nick.zoobank.account < 0) {         //штрафы в случае невыплаты
            nick.fines_count++;
            RUB bank_fine = 5000;

            nick.credit.body += bank_fine;      //долг растет, если не заплатил
            nick.fines += bank_fine;
            printf("  [BANK WARNING]: Nick v minuse! Shtraf +%lld k dolgu.\n", bank_fine);
        }

        if (nick.credit.months_left == 0) {     //для последнего платежа
            nick.credit.body = 0;       //обнуление на всякий случай
            printf("  [NICK]: 'Ura! YA raspravilsya s etim kreditom!'\n");
        }
    }
}


void nick_expenses()        //расходы Ника
{
    nick.zoobank.account -= nick.food;
    nick.total_earned += nick.food;

    nick.zoobank.account -= nick.car.gas;
    nick.total_earned += nick.car.gas;
}


void nick_shadow_expenses(int month)        //"теневые" расходы Ника
{              
    RUB protection_fee = 8000;             //ник платит 'долю' Мистеру Бигу за ведение бизнеса в его районе
    nick.zoobank.account -= protection_fee;
    nick.business_events_count++;
    nick.total_spent += protection_fee;
    
    
    if (month % 4 == 0) {           //дополнительный риск: иногда бизнес работает в ноль или минус
        RUB spoiled_pizza = 3500; //продукты испортились
        nick.zoobank.account -= spoiled_pizza;
        nick.total_spent += spoiled_pizza;
        printf("  [NICK TROUBLE]: Produkty isportilis'! Poteryano %lld RUB\n", spoiled_pizza);
    }
}


void nick_black_market_exchange(int month, int year)            //черный рынок обмена валют (для Ника) 
{
    if (nick.zoobank.account > 20000 && month % 4 == 0) {       //Ник пытается провернуть сделку, если у него больше 20000 рублей на счету
        int risk = (month * year) % 10;
        nick.black_market_count++;              //счетчик попыток сделок
        printf("  [BLACK MARKET]: Nik pytaetsya obmenyat' valyutu... ");

        if (risk > 2) {                     //70% шанс на успех
            RUB sum = 10000;                //сумма для обмена - 10000
            
            float lucky_rate = judy.zoobank.rate_usd_rub * 0.85;     //у Ника курс выгоднее, чем в банке на 15%
            USD bought = (USD)(sum / lucky_rate);

            nick.zoobank.account -= sum;
            nick.zoobank.account_usd += bought;
            printf("USPEH! Obmenyal po kursu %.2f. Polucheno %lld USD.\n", lucky_rate, bought);
        }
        else {                              //30% шанс, что Ника кинули или накрыла полиция
            RUB penalty = 10000;
            nick.fines_count++;
            nick.zoobank.account -= penalty;
            nick.total_spent += penalty;
            printf("PROVAL! Nik natknulsya na moshennikov. Poteryano %lld RUB.\n", penalty);
        }
    }
}


void nick_law_compliance(int month, int year)        //функция оплаты штрафов
{        
    if (nick.fines > 0) {
        printf("  [POLICE DEPARTMENT]: Nick imeet neoplachennye shtrafy (%lld RUB).\n", nick.fines);
        
        if (nick.zoobank.account > 30000) {         //если денег достаточно, чтобы оплатить хотя бы часть (например, более 30к на счету)
            RUB payment = 0;

            if (nick.zoobank.account >= nick.fines) {
                payment = nick.fines;           //олатит всё сразу
                printf("  [NICK]: 'Ekh, polnost'yu ochishchayu svoyu sovest'...' -%lld RUB\n", payment);
            }

            else {
                payment = 15000;                //оплатит частями, если денег не очень много
                printf("  [NICK]: 'Oplachivayu chast' shtrafov, chtoby otstali.' -%lld RUB\n", payment);
            }

            nick.zoobank.account -= payment;
            nick.fines -= payment;
        }
        else {            
            RUB penalty = 1000;         // Если денег нет, долг просто висит и может вырасти (пени)
            nick.fines += penalty;
            printf("  [SYSTEM]: Nick ne mozhet oplatit' shtrafy. Nachisleny peni: +%lld RUB\n", penalty);
        }
        printf("  --------------------------------------------------\n");
    }
}



// ОГРОМНАЯ ФУНКЦИЯ ЖИЗНЕННЫХ СОБЫТИЙ НИКА УАЙЛДА (имитирует хаотичную жизнь в Зверополисе, события влияют на баланс, бизнес или текущие расходы)

void nick_life_events(int month, int year) 
{

    int event_id = (month * 17 + year * 3) % 40;    //другая формула (не как у Джуди) для выбора события (без использования rand()), имитирует "случайные" события

    printf("  [NICK STORY]: ");

    switch (event_id) {
    case 0:
        printf("Nick prodal partiyu 'Lapo-ledentsov' slonam. +15000 RUB\n\n");
        nick.zoobank.account += 15000;
        nick.total_earned += 15000;
        nick.business_events_count++;
        break;
    case 1:
        printf("Noviy kontrakt s Politehom na postavku picci. +5000 RUB\n\n");
        nick.Nickizza.monthly_profit += 5000;
        nick.business_events_count++;
        break;
    case 2:
        printf("Mister Big prigrozil za starye dolgi. Prishlos' otdat' 'protsent za uvazhenie'. -10000 RUB\n\n");
        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        nick.business_events_count++;
        break;
    case 3:
        printf("Judy pomogla zakryt' shtrafy Nicka po staroy druzhbe. +5000 RUB\n\n");
        nick.zoobank.account += 5000;
        nick.total_earned += 5000;
        nick.rescue_events_count++;
        nick.business_events_count++;
        break;
    case 4:
        printf("Nick nashel skidku na syr dlya pitstsy. Pribyl' 'Nickiccy' rastet!\n\n");
        nick.Nickizza.monthly_profit += 2000;
        nick.business_events_count++;
        break;
    case 5:
        printf("Furgon slomalsya pryamo posredi dorogi. Srochnyy remont dvigatelya. -25000 RUB\n\n");
        nick.zoobank.account -= 25000;
        nick.total_spent += 25000;
        nick.business_events_count++;
        break;
    case 6:
        printf("Nick pereprodal bilet v operu baranu-mafiose. +18500 RUB\n\n");
        nick.zoobank.account += 18500;
        nick.total_earned += 18500;
        nick.business_events_count++;
        break;
    case 7:
        printf("Nalogovaya inspektsiya proverila scheta 'Nickiccy'. Prishlos' zaplatit' nalog. -15000 RUB\n\n");
        nick.zoobank.account -= 15000;
        nick.total_spent += 15000;
        nick.fines_count++;
        nick.business_events_count++;
        break;
    case 8:
        printf("Vypala nevidannaya udacha v ulichnuyu lotereyu 'Hvost Udachi'! +10000 RUB\n\n");
        nick.zoobank.account += 10000;
        nick.total_earned += 10000;
        nick.business_events_count++;
        break;
    case 9:
        printf("Nick kupil novyy dorogoy galstuk dlya vstrechi s investorami. -4500 RUB\n\n");
        nick.zoobank.account -= 4500;
        nick.total_spent += 4500;
        nick.business_events_count++;
        break;
    case 10:
        printf("doch' Mistera Biga stala postoyannym klientom. Pribyl' rastet! +5000 RUB\n\n");
        nick.Nickizza.monthly_profit += 5000;
        nick.business_events_count++;
        break;
    case 11:
        printf("Nick reshil s'ekonomit' na nalogakh, no ego poimali. Shtraf! -20000 RUB\n\n");
        nick.fines += 20000;
        nick.fines_count++;
        nick.business_events_count++;
        break;
    case 12:
        printf("Vygodnyy obmen valyuty u podpol'nykh dilerov v ruyone Tundratown. +1000 USD\n\n");
        nick.zoobank.account_usd += 1000;
        nick.black_market_count++;
        nick.business_events_count++;
        break;
    case 13:
        printf("Nick kupil stil'nye ochki, chtoby vyglyadet' solidnee. -6000 RUB\n\n");
        nick.zoobank.account -= 6000;
        nick.total_spent += 6000;
        nick.business_events_count++;
        break;
    case 14:
        printf("Sosedi pozhalovalis' na shum ot pechi dlya pitstsy. Vzyatka inspektoru. -4000 RUB\n\n");
        nick.zoobank.account -= 4000;
        nick.total_spent += 4000;
        nick.business_events_count++;
        break;
    case 15:
        printf("Judy zabyla obed, i Nick ugostil ee koronnoiy pitstsey. -1000 RUB.\n\n");
        nick.zoobank.account -= 1000;
        nick.total_spent += 1000;
        nick.business_events_count++;
        break;
    case 16:
        printf("Nick nashel novogo postavshchika muki. Zatraty snizilis'.\n\n");
        nick.Nickizza.monthly_profit += 3000;
        nick.business_events_count++;
        break;
    case 17:
        printf("Vystavka malogo biznesa v Zveropolise. Nick poluchil pochetnyy grant! +50000 RUB\n\n");
        nick.zoobank.account += 50000;
        nick.total_earned += 50000;
        nick.business_events_count++;
        break;
    case 18:
        printf("Kto-to skrutil zerkala s furgona Nicka noch'yu. -4000 RUB\n\n");
        nick.zoobank.account -= 4000;
        nick.total_spent += 4000;
        nick.business_events_count++;
        break;
    case 19:
        printf("Glavnyy povar 'Nickiccy' ushel v otpusk. Ubytki. -6000 RUB\n\n");
        nick.zoobank.account -= 6000;
        nick.total_spent += 6000;
        nick.business_events_count++;
        break;
    case 20:
        printf("Nick zaregistriroval novyy brend 'Wild Pizza'. Investitsii v marketing. -15000 RUB\n\n");
        nick.Nickizza.investment += 15000;
        nick.zoobank.account -= 15000;
        nick.total_spent += 15000;
        nick.business_events_count++;
        break;
    case 21:
        printf("Krysha garazha protekla vo vremya dozhdya. Nuzhen remont. -5000 RUB\n\n");
        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        nick.business_events_count++;
        break;
    case 22:
        printf("Selfi Nicka s pitstsey stalo virusnym v setyakh. Reklama! +10000 RUB\n\n");
        nick.zoobank.account += 10000;
        nick.total_earned += 10000;
        nick.business_events_count++;
        break;
    case 23:
        printf("Nick popal v probku iz-za lenivtsev. Opovzdal na vazhnuyu sdelku. -3000 RUB\n\n");
        nick.zoobank.account -= 3000;
        nick.total_spent += 3000;
        nick.business_events_count++;
        break;
    case 24:
        printf("Mister Big podaril Nicku staryy antikvarnyy shkaf. Tam byl tayNick! +25000 RUB\n\n");
        nick.zoobank.account += 25000;
        nick.total_earned += 25000;
        nick.business_events_count++;
        break;
    case 25:
        printf("Zabastovka fermerov. Produkty dlya lichnoy zhizni podorozhali. -4000 RUB\n\n");
        nick.food += 4000;
        nick.business_events_count++;
        break;
    case 26:
        printf("Nick vyigral v kosti u odnogo upyortogo barana. +15000 RUB\n\n");
        nick.zoobank.account += 15000;
        nick.total_earned += 15000;
        nick.black_market_count++;
        nick.business_events_count++;
        break;
    case 27:
        printf("Nochnoe ograblenie furgona! Vorishki vskryli seyf. -11000 RUB\n\n");
        nick.zoobank.account -= 11000;
        nick.total_spent += 11000;
        nick.business_events_count++;
        break;
    case 28:
        printf("Nick reshil stat' fud-blogerom i kupil doroguyu kameru. -30000 RUB\n\n");
        nick.zoobank.account -= 30000;
        nick.total_spent += 30000;
        nick.business_events_count++;
        break;
    case 29:
        printf("Bol'shoy zakaz dlya morskikh svinok. 100 mini-pitsts! +10000 RUB\n\n");
        nick.zoobank.account += 10000;
        nick.total_earned += 10000;
        nick.business_events_count++;
        break;
    case 30:
        printf("Nick nashel na svalke rariternuyu zapchast' i prodal ee kollektsioneru. +7000 RUB\n\n");
        nick.zoobank.account += 7000;
        nick.total_earned += 7000;
        nick.business_events_count++;
        break;
    case 31:
        printf("Odin iz kuryerov Nicka poteryal sumku s den'gami. -5000 RUB\n\n");
        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        nick.business_events_count++;
        break;
    case 32:
        printf("Nick organizoval ulichnyy kvest dlya turistov. +9000 RUB\n\n");
        nick.zoobank.account += 9000;
        nick.total_earned += 9000;
        nick.business_events_count++;
        break;
    case 33:
        printf("Kholodil'nik v 'Nickicce' vyshel iz stroya. Produkty isportilis'. -8000 RUB\n\n");
        nick.zoobank.account -= 8000;
        nick.total_spent += 8000;
        nick.business_events_count++;
        break;
    case 34:
        printf("Nick sluchayno pomog staromu slonu pereyti dorogu. Poluchil chaevye. +1000 RUB\n\n");
        nick.zoobank.account += 1000;
        nick.total_earned += 1000;
        nick.business_events_count++;
        break;
    case 35:
        printf("Vstretil Blica na pochte. Poteryal ves' den' v ocheredi. Business prostoial. -3000 RUB\n\n");
        nick.zoobank.account -= 3000;
        nick.total_spent += 3000;
        nick.business_events_count++;
        break;
    case 36:
        printf("Pomyal bamper na furgone ob klumbu. -4000 RUB\n\n");
        nick.zoobank.account -= 4000;
        nick.total_spent += 4000;
        nick.business_events_count++;
        break;

    default:
        printf("Obychnyy mesyac' ulichnogo lisa. Nichego ne proishodilo.\n\n");
        break;
    }
}


void print_nick_report(int month, int year)             //вывод результатов Ника
{               
    printf("\n  _______________________________________________________  \n");
    printf(" /                                                       \\ \n");
    printf("|   DELISHKI Nicka UAYLDA (BUSINESS LOG)                  |\n");
    printf("|   Mesyats: %02d, God: %d                                |\n", month - 1, year);
    printf("|  -----------------------------------------------------  |\n");
    printf("|   Nalichka v karmane:     %15lld RUB           |\n", nick.zoobank.account);
    printf("|   Pribil' s piccy:        %15lld RUB           |\n", nick.Nickizza.monthly_profit);
    printf("|  -----------------------------------------------------  |\n");
    printf("|   DOLGI:                                                |\n");
    printf("|   Ostatok po kreditu:     %15lld RUB           |\n", nick.credit.body);
    printf("|   Mesyatsev platit':      %15d               |\n", nick.credit.months_left);
    printf("|  -----------------------------------------------------  |\n");
    printf("|   STATUS: %-30s                |\n", (nick.zoobank.account < 0 ? "VSE PLOHO (KOLLEKTORY!)" : "ZHIT' MOZHNO"));
    printf(" \\_______________________________________________________/ \n");
    printf("\n");
    printf("\n");
}


//ДЖУДИ

void judy_salary(const int month, const int year)           //функция зарплаты Джуди
{
    if (month == 12) {
        judy.zoobank.account += judy.salary;  // 13th salary
    }

    judy.zoobank.account += judy.salary;
    judy.total_earned += judy.salary; //считаем деньги
    judy.salary_payments_count++;      //считаем разы
}


void judy_food()                            //функция еды Джуди
{
    judy.zoobank.account -= judy.food;
    judy.total_spent += judy.food;       //счетчик общих трат
    judy.food_payments_count++;          //счетчик количества покупок
}


void judy_car()                             //функция машины Джуди
{
    judy.zoobank.account -= judy.car.gas;
    judy.total_spent += judy.car.gas;    //счетчик общих трат
    judy.gas_payments_count++;           //счетчик заездов на заправку
}


// Вспомогательные функции для будущего расширения 
void judy_home();

float key_rate(const int month, const int year)              //функция ключевой ставки
{
    Percent percents_rate;
    if (year == 2026) percents_rate = 14.5;
    if (year == 2027) percents_rate = 12.5;
    if (year == 2028) percents_rate = 10;
    if (year == 2029) percents_rate = 7.5;
    if (year == 2030) percents_rate = 4;
    if (year == 2031) percents_rate = 4.5;
    return (percents_rate);
}

float delta(const int month, const int year)              //функция (ставка - % по депозиту или предложение по кредиту - ставка, 2026-2030гг)
{
    Percent percents_delta;
    if (year == 2026) percents_delta = 2.5;
    if (year == 2027) percents_delta = 2.5;
    if (year == 2028) percents_delta = 2;
    if (year == 2029) percents_delta = 1.5;
    if (year == 2030) percents_delta = 1;
    if (year == 2031) percents_delta = 1.5;
    return (percents_delta);
}


void judy_deposite(const int month, const int year)         //функция депозита Джуди в банке
{
    judy.zoobank.interest = key_rate(month, year) - delta(month, year);     //ключевая ставка - дельта ("комиссия" банка)

    judy.zoobank.deposite += (RUB)(judy.zoobank.deposite * (judy.zoobank.interest / 12.0 / 100.0));    //сложный процент
    
    if (judy.zoobank.account > 0){
        judy.zoobank.deposite += judy.zoobank.account;      //если все норм
        judy.zoobank.account = 0;
    }
    else if (judy.zoobank.account < 0) {
        printf("  [BANK]: Vnimanie! Otricatel'nyy balans na schetu Judy (%lld). Pogashenie iz depozita.\n", judy.zoobank.account);
        judy.zoobank.deposite += judy.zoobank.account; //вычитание долга из накоплений
        judy.zoobank.account = 0;
    }
    
}


void judy_freelance(const int month, const int year)            //функция подработки Джуди
{
    if (month == 3 and year == 2027) {
        judy.zoobank.account_usd += 3'000;
    }
}


void judy_currency_exchange(int month)          //официальный обмен в банке (для Джуди)
{
    // Джуди меняет фиксированную сумму 10 000 рублей на доллары каждый квартал
    if (month % 3 == 0) {
        RUB sum_to_exchange = 10000;
        if (judy.zoobank.account >= sum_to_exchange) {
            float bank_commission = 0.05; // Комиссия банка 5%
            USD bought_usd = (USD)((sum_to_exchange * (1.0 - bank_commission)) / judy.zoobank.rate_usd_rub);

            judy.zoobank.account -= sum_to_exchange;
            judy.zoobank.account_usd += bought_usd;

            printf("  [VALYUTNI BANK]: Operaciya obmena. Kupleno %lld USD s komissiey 5%%.\n", bought_usd);
        }
    }
}
void judy_medine(int month, int year) {     //медицина Джуди
    int med_id = (month * 3 + year) % 15;   //еще "случайный" выбор
    printf("  [HEALTH]: ");

    switch (med_id) {
    case 0:
        printf("Judy proshla planovuyu dispanserizaciyu. -2000 RUB\n");
        judy.zoobank.account -= 2000;
        judy.medicine_events_count++;
        judy.total_spent += 2000;
        break;
    case 1:
        printf("Kupila vitaminy dlya bystrogo bega. -3500 RUB\n");
        judy.zoobank.account -= 3500;
        judy.medicine_events_count++;
        judy.total_spent += 2000;
        judy.total_earned += 3500;
        break;
    case 2:
        printf("Zaboleli ushi iz-za vetra. Pokupka kapel'. -1500 RUB\n");
        judy.zoobank.account -= 1500;
        judy.medicine_events_count++; 
        judy.total_spent += 1500;
        break;
    case 3:
        printf("Stomatolog v Zveropolise - eto dorogo! -15000 RUB\n");
        judy.zoobank.account -= 15000;
        judy.medicine_events_count++; 
        judy.total_spent += 15000;
        break;
    case 4:
        printf("Oplatila medicinskuyu strahovku na polgoda. -25000 RUB\n");
        judy.zoobank.account -= 25000; 
        judy.medicine_events_count++; 
        judy.total_spent += 25000;
        break;
    default:
        printf("Judy chuvstvuet sebya prekrasno! Zdorov'e v norme.\n");
        break;
    }
}

// ОГРОМНАЯ ФУНКЦИЯ СЛУЖБЫ В ПОЛИЦИИ ДЖУДИ ХОППС (описывает рабочие смены, премии, выезды и расходы на службу)
void judy_police_life(int month, int year) 
{
    
    judy.police_events_count++;
    int duty_id = (month * 11 + year * 5) % 40;     //просто формула для выбора события (без использования rand()), имитирует "случайные" события
    printf("  [JUDY POLICE DUTY]: ");

    switch (duty_id) {
    case 0:
        printf("Judy vistupila s lekciey v Polytehe. Respect + 2000 RUB\n");
        judy.zoobank.account += 2000;
        judy.total_earned += 2000;
        judy.police_events_count++;
        break;
    case 1:
        printf("Celyy den' na postu pod dozhdem. Kupila goryachiy chaj i lekarstva. -1500 RUB\n");
        judy.zoobank.account -= 1500;
        judy.total_spent += 1500;    
        judy.police_events_count++;
        break;
    case 2:
        printf("Uspeshno rascryto delo o propazhe zebry. Blagodarnost' ot Shefa Bogo.\n");
        judy.police_events_count++;
        break;
    case 3:
        printf("Judy sluchaino razbila raciyu. Vychet iz zarplaty. -3000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 3000;
        judy.total_spent += 3000;
        break;
    case 4:
        printf("Kupila ogromnuyu korobku ponchikov dlya Kogtyauzera. -2000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;
        break;
    case 5:
        printf("Nochnoe dezhurstvo v Tundratoune. Nadbavka za nochnye smeny. +4000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 4000;
        judy.total_earned += 4000;
        break;
    case 6:
        printf("Judy kupila novye krossovki. -6000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 6000;
        judy.total_spent += 6000;
        break;
    case 7:
        printf("Pobeda v konkurse 'Luchshiy policeyskiy mesyaca'. Gran-pri! +15000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 15000;
        judy.total_earned += 15000;
        break;
    case 8:
        printf("Zapravila sluzhebnyy motocikl za svoy schet po oshibke. -2500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 2500;
        judy.total_spent += 2500;
        break;
    case 9:
        printf("Pomogla pozhiloy slonikhe nayti dorogu. Poluchila morkovnyy pirog (ekonomiya na ede). +1000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 1000;
        judy.total_earned += 1000;
        break;
    case 10:
        printf("Uchastie v specoperacii v tropicheskom rayone. Komandirovochnye. +7000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 7000;
        judy.total_earned += 7000;
        break;
    case 11:
        printf("Judy vyvernula lapu pri zaderzhanii. Platnaya klinika. -4500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 4500;
        judy.total_spent += 4500;
        break;
    case 12:
        printf("Shtraf za prevyshenie skorosti na sluzhebnom avto. -2000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;
        break;
    case 13:
        printf("Podarok dlya roditeley. Otpravila posylku. -5000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 5000;
        judy.total_spent += 5000;
        break;
    case 14:
        printf("Denezhnyy perevod ot roditeley. +3500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 3500;
        judy.total_earned += 3500;
        break;
    case 15:
        printf("Kupila novyy fonarik dlya osmotra temnykh pereulkov. -1200 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 1200;
        judy.total_spent += 1200;
        break;
    case 16:
        printf("Zaderzhala bandu morkovnykh vorov. Gorodskaya nagrada! +10000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 10000;
        judy.total_earned += 10000;
        break;
    case 17:
        printf("Sluzhebnoe obuchenie ekstremal'nomu vozhdeniyu.\n");
        judy.police_events_count++;
        break;
    case 18:
        printf("Poteryala kvitanciyu na vyplatu strahovki. Ubytki. -3000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 3000;
        judy.total_spent += 3000;
        break;
    case 19:
        printf("Obed s Merom Zlatogrivym. Prishlos' sootvetstvovat' dress-kodu. -8000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 8000;
        judy.total_spent += 8000;
        break;
    case 20:
        printf("Sdala examen v policii na otlichno. Povyshenie klassnosti! +2000 RUB k okladu.\n");
        judy.police_events_count++;
        judy.salary += 2000;
        break;
    case 21:
        printf("Zabyla vyklyuchit' mayachok, sel akkumulyator. Remont. -2500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 2500;
        judy.total_spent += 2500;
        break;
    case 22:
        printf("Blagotvoritel'nyy marafon policii. Pozhertvovanie. -1500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 1500;
        judy.total_spent += 1500;
        break;
    case 23:
        printf("Judy nashla uliku v starom dele. Dosrochnaya premiya. +6000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 6000;
        judy.total_earned += 6000;
        break;
    case 24:
        printf("Sluzhebnaya forma porvalas'. Novyy komplekt. -4000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 4000;
        judy.total_spent += 4000;
        break;
    case 25:
        printf("Den' otkrytykh dverey v policii. Kupila vozdushnye shary dlya detey. -1000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 1000;
        judy.total_spent += 1000;
        break;
    case 26:
        printf("Vypolnila plan po shtrafam za mesyac. Bonus ot departamenta. +5000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 5000;
        judy.total_earned += 5000;
        break;
    case 27:
        printf("Popytka podkupa! Judy chestnaya, no prishlos' pisat' otchety ves' den'.\n");
        judy.police_events_count++;
        break;
    case 28:
        printf("Kupila morkovnyy sok dlya vsey smeny. Podnyala boevoy duh. -2000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;
        break;
    case 29:
        printf("Zaderzhanie opasnogo prestupnika. Riskovye vyplaty. +12000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 12000;
        judy.total_earned += 12000;
        break;
    case 30:
        printf("Remont sluzhebnoiy mashiny posle tarana. Chastichnaya oplata. -7000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 7000;
        judy.total_spent += 7000;
        break;
    case 31:
        printf("Judy priglashena lektorom v akademiyu. Gonorar. +8000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 8000;
        judy.total_earned += 8000;
        break;
    case 32:
        printf("Poteryala lyubimuyu ruchku-morkovku s diktofonom. Novaya stoit dorogo. -3000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 3000;
        judy.total_spent += 3000;
        break;
    case 33:
        printf("Prorvalo trubu v kvartire. Prishlos' spat' v otele. -4500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 4500;
        judy.total_spent += 4500;
        break;
    case 34:
        printf("Judy nashla poteryannyy koshelek i vernula vladel'cu. Nakladnye raskhody. -500 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account -= 500;
        judy.total_spent += 500;
        break;
    case 35:
        printf("Judy poimala vora sumochek. Premiya! +5000 RUB\n");
        judy.police_events_count++;
        judy.zoobank.account += 5000;
        judy.total_earned += 5000;
        break;

    default:
        printf("Spokoynaya smena v Zveropolise. Proisshestviy ne zafiksirovano.\n");
        break;
    }
}


void print_judy_report(int month, int year, RUB deposit_at_start)           //вывод результатов Джуди
{
    RUB profit = judy.zoobank.deposite - deposit_at_start;
    RUB total_assets = judy.zoobank.account + judy.zoobank.deposite +
        judy.car.value + (judy.zoobank.account_usd * judy.zoobank.rate_usd_rub);

    printf("\n.========================================================.\n");
    printf("|       OTCHET POLICII ZVEROPOLISA (OFFICER HOOPS)       |\n");
    printf("|--------------------------------------------------------|\n");
    printf("|   Mesyats: %02d, God: %d                               |\n", month - 1, year);
    printf("|--------------------------------------------------------|\n");
    printf("| POKAZATEL'          | ZNACHENIE                        |\n");
    printf("|---------------------|----------------------------------|\n");
    printf("| Depozit (vklad)     | %15lld RUB              |\n", judy.zoobank.deposite);
    printf("| Valyuta ($)         | %15lld USD              |\n", judy.zoobank.account_usd);
    printf("|---------------------|----------------------------------|\n");
    printf("| Zarplata            | %15lld RUB              |\n", judy.salary);
    printf("| Produkty            | %15lld RUB              |\n", judy.food);
    printf("| Mashina (ocenka)    | %15lld RUB              |\n", judy.car.value);
    printf("|---------------------|----------------------------------|\n");
    printf("| PRIBIL' ZA GOD      | %15lld RUB              |\n", profit);
    printf("| ITOGO KAPITAL       | %15lld RUB              |\n", total_assets);
    printf("'========================================================'\n");
}


//ГИГАНТСКАЯ СИСТЕМА СОБЫТИЙ ЗВЕРОПОЛИСА, касающаяся всех
//функция генерирует 50 различных сценариев, меняющих экономику

void world_news(int month, int year) 
{    
    int news_id = (month * 31 + year * 13) % 81;        //еще одна сложная формула выбора "случайной" новости для разнообразия

    printf(" [ZOOTOPIA DAILY NEWS]: ");

    switch (news_id) {
    case 0:
        printf("Zabastovka lenivcev v departamente transporta! Logistika vstala.\n");
        nick.car.gas += 3000;

        judy.car.gas += 3000;
        break;
    case 1:
        printf("Gazelle vypustila novyy albom. Vse tratyat dengi na bilety. -2000 RUB\n");
        nick.zoobank.account -= 2000;
        nick.total_spent += 2000;

        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;
        break;
    case 2:
        printf("Anomalnaya zhara. Eda dorozhaet na 20%%.\n");
        judy.food = (RUB)(judy.food * 1.2);

        nick.food = (RUB)(nick.food * 1.2);
        break;
    case 3:
        printf("Mer Zlatogriv ob'yavil nalogovye kanikuly dlya picceriy! +5000 RUB\n");
        nick.zoobank.account += 5000;
        nick.total_earned += 5000;
        break;
    case 4:
        printf("V Tundratoune morozy. Zatraty na obogrev furgona vyrosli. -4000 RUB\n");
        nick.car.gas += 4000;
        break;
    case 5:
        printf("Blic (lenivec) stal licom 'Bystryh Kreditov'. Procenty snizheny.\n");
        nick.credit.interest -= 1.0;
        break;
    case 6:
        printf("Otkrytie novogo metro. Ceny na ulichnuyu edu upali. -1000 RUB pribyli.\n");
        nick.Nickizza.monthly_profit -= 1000;
        break;
    case 7:
        printf("Epidemiya!!! Vse pokupayut lekarstva. -5000 RUB\n");
        judy.zoobank.account -= 5000;
        judy.total_spent += 5000;

        nick.zoobank.account -= 3000;
        nick.total_spent += 3000;
        break;
    case 8:
        printf("Zveropolis prinimaet festival' morkovki! Turisty v gorode. +15000 RUB\n");
        nick.zoobank.account += 15000;
        nick.total_earned += 15000;
        break;
    case 9:
        printf("Vveden nalog na hvosty. Kazhdyy zaplatil po 1500 rubley.\n");
        judy.zoobank.account -= 1500;
        judy.total_spent += 1500;

        nick.total_spent += 1500;
        nick.zoobank.account -= 1500;
        break;
    case 10:
        printf("Sboy v bankovskoy sisteme. Depozity prinesli menshe deneg.\n");
        judy.zoobank.deposite -= 5000;
        judy.total_spent += 5000;
        break;
    case 11:
        printf("Nik nashel optovogo postavshchika syra. Picca deshevle v proizvodstve.\n");
        nick.Nickizza.monthly_profit += 4000;
        break;
    case 12:
        printf("Policeyskaya oblava v Tundratoune. Den'gi Nicka poteryalis na chernom rinke.\n");
        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        break;
    case 13:
        printf("Judy poluchila pochetnuyu gramotu. Roditeli prislali podarok. +5000 RUB\n");
        judy.zoobank.account += 5000;
        judy.total_earned += 5000;
        break;
    case 14:
        printf("Udorozhanie morkovnogo topliva. Benzin +15%%.\n");
        judy.car.gas = (RUB)(judy.car.gas * 1.15);

        nick.car.gas = (RUB)(nick.car.gas * 1.15);
        break;
    case 15:
        printf("Mister Big rasshiryaet vliyanie. 'Nalog na bezopasnost' dlya Nicka. -10000 RUB\n");
        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        break;
    case 16:
        printf("Vystavka avto. Mashina Judy podorozhala! +50000 RUB\n");
        judy.car.value += 50000;
        break;
    case 17:
        printf("Sosedi Nicka ustroili potop. Remont furgona. -12000 RUB\n");
        nick.zoobank.account -= 12000;
        nick.total_spent += 12000;
        break;
    case 18:
        printf("Blagotvoritel'nyy fons 'Lapa Pomoshchi'. Dobrovol'noe pozhertvovanie.\n");
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;

        nick.zoobank.account -= 1000;
        nick.total_spent += 1000;
        break;
    case 19:
        printf("V Zveropolise poyavilsya novyy konkurent 'Mishizza'. Pribyl' padaet.\n");
        nick.Nickizza.monthly_profit -= 5000;
        break;
    case 20:
        printf("Zolotaya osen'. Produkty desheveyut na 10%%.\n");
        judy.food = (RUB)(judy.food * 0.9);

        nick.food = (RUB)(nick.food * 0.9);
        break;
    case 21:
        printf("Nick vyigral v kosti u barana. +25000 RUB nalichnymi!\n");
        nick.zoobank.account += 25000;
        nick.total_earned += 25000;
        break;
    case 22:
        printf("Judy sluchayno udarila sluzhebnuyu mashinu. Strahovka podorozhala.\n");
        judy.zoobank.account -= 4000;
        judy.total_spent += 4000;
        break;
    case 23:
        printf("V gorode proshli voennie ucheniya. Vse magaziny zakryty.\n");
        nick.zoobank.account -= nick.Nickizza.monthly_profit / 30;
        nick.total_spent += nick.Nickizza.monthly_profit / 30;
        break;
    case 24:
        printf("Roditeli Judy priehali v gosti. Traty na priem rodni. -15000 RUB\n");
        judy.zoobank.account -= 15000;
        judy.total_spent += 15000;
        break;
    case 25:
        printf("Nick reshil investirovat' v kriptovalyutu 'Morkovkoin'. Proigral. -20000 RUB\n");
        nick.zoobank.account -= 20000;
        nick.total_spent += 20000;
        break;
    case 26:
        printf("Den' ponchika! Besplatnyy zavtrak v uchastke. +500 RUB Judy.\n");
        judy.zoobank.account += 500;
        judy.total_earned += 500;
        break;
    case 27:
        printf("Staryy friend Nicka vernul dolg. +8000 RUB\n");
        nick.zoobank.account += 8000;
        nick.total_earned += 8000;
        break;
    case 28:
        printf("Inspekciya sanstancii v 'Nickicce'. Vzyatka... t.e. shtraf. -7000 RUB\n");
        nick.zoobank.account -= 7000;
        nick.total_spent += 7000;
        nick.fines += 7000;
        break;
    case 29:
        printf("V Zveropolise bumnaya svad'ba u gryzunov. Zakazali 500 picc! +30000 RUB\n");
        nick.zoobank.account += 30000;
        nick.total_earned += 30000;
        break;
    case 30:
        printf("U Judy slomalas' kofemashina. Pokupka novoy. -4500 RUB\n");
        judy.zoobank.account -= 4500;
        judy.total_spent += 4500;
        break;
    case 31:
        printf("Inflaciya okazalas' vyshe prognozov. Ceny skachut.\n");
        judy.food += 1000;

        nick.food += 1000;
        break;
    case 32:
        printf("Nick kupil rariternuyu plastinku dlya Mistera Biga. -6000 RUB\n");
        nick.zoobank.account -= 6000;
        nick.total_spent += 6000;
        break;
    case 33:
        printf("Snegopad v Tundratoune. Judy rabotala sverykhurochno. +6000 RUB\n");
        judy.zoobank.account += 6000;
        judy.total_earned += 6000;
        break;
    case 34:
        printf("Krysy peregryzli provoda v piccerii. Remont. -9000 RUB\n");
        nick.zoobank.account -= 9000;
        nick.total_spent += 9000;
        break;
    case 35:
        printf("Judy nashla 5000 rubley na trotuare i sdala v byuro nahodok.\n");
        break;
    case 36:
        printf("Vvedeny sankcii na importnyy syr. Picca dorozhaet.\n");
        nick.Nickizza.monthly_profit += 2000;
        break;
    case 37:
        printf("U Nicka den' rozhdeniya! Judy podarila galstuk. -5000 RUB Judy.\n");
        judy.zoobank.account -= 5000;
        judy.total_spent += 5000;

        nick.total_earned += 5000;
        nick.zoobank.account += 5000;
        break;
    case 38:
        printf("Obval rynka. Nick poteryal chast' investiciy. -15000 RUB\n");
        nick.Nickizza.investment -= 15000;
        break;
    case 39:
        printf("Novyy proekt Judy po svyazyam s obshchestvennostyu. Premiya +4000 RUB\n");
        judy.zoobank.account += 4000;
        judy.total_earned += 4000;
        break;
    case 40:
        printf("V piccerii sluchilsya pozhar. Chastichnoe vosstanovlenie. -40000 RUB\n");
        nick.zoobank.account -= 40000;
        nick.total_spent += 40000;
        break;
    case 41:
        printf("Judy vyigrala konkurs po strel'be. +7000 RUB\n");
        judy.zoobank.account += 7000;
        judy.total_earned += 7000;
        break;
    case 42:
        printf("Udorozhanie arendy garazha dlya furgona. -2000 RUB v mesyac.\n");
        nick.car.gas += 2000;
        break;
    case 43:
        printf("Mery Zveropolisa vydelyayut subsidii na mashiny. +10000 RUB\n");
        judy.zoobank.account += 10000;
        judy.total_earned += 10000;

        nick.zoobank.account += 10000;
        nick.total_earned += 10000;
        break;
    case 44:
        printf("Nick popalsya na krazhe morkovnogo soka. Judy oshtrafovala ego. -5000 / +1000\n");
        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        nick.fines_count++;

        judy.zoobank.account += 1000;
        judy.total_earned += 1000;
        break;
    case 45:
        printf("Gazelle ustraivaet morkovnyy marafon. Vse tratyat na sport. -2000 RUB\n");
        judy.zoobank.account -= 2000;        
        judy.total_spent += 2000;

        nick.zoobank.account -= 2000;
        nick.total_spent += 2000;
        break;
    case 46:
        printf("Uspeshnyy barter: Nik obmenyal staruyu pech na novye kolesa.\n");
        nick.car.value += 25000;
        // Бартер — это обмен активами, нал не меняется
        break;
    case 47:
        printf("Policeyskiy bal. Traty na plate i kostyum. -15000 RUB oboim.\n");
        judy.zoobank.account -= 15000;        
        judy.total_spent += 15000;

        nick.zoobank.account -= 15000;
        nick.total_spent += 15000;
        break;
    case 48:
        printf("Nik otkryl dlya sebya dostavku dronom. Pribyl' +7000 RUB\n");
        nick.Nickizza.monthly_profit += 7000;
        nick.business_events_count++;
        break;
    case 49:
        printf("Global'nyy krizis edy! Vse tratyat zapasy. -10000 RUB\n");
        judy.zoobank.account -= 10000;        
        judy.total_spent += 10000;

        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        break;

    case 50: 
        printf("Otkrytie novogo akvaparka. -5000 RUB\n"); 
        judy.zoobank.account -= 5000;
        judy.total_spent += 5000;

        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        break;
    case 51:
        printf("Prazdnik morkovnogo feyerverka. +2000 RUB\n"); 
        judy.zoobank.account += 2000;
        judy.total_earned += 2000;

        nick.zoobank.account += 2000;
        nick.total_earned += 2000;
        break;
    case 52: 
        printf("Otkritie punktov sbora shin. Nick prodaet starye kolesa. +8000 RUB\n");
        nick.zoobank.account += 8000; 
        nick.total_earned += 8000;
        break;
    case 53:
        printf("Morozy. Benzin +1000\n"); 
        nick.car.gas += 1000;

        judy.car.gas += 1000;
        break;
    case 54:
        printf("Judy poluchila znachok. Nick pozdravil +5000/-1000 RUB\n"); 
        judy.zoobank.account += 5000;
        judy.total_earned += 5000;

        nick.zoobank.account -= 1000;
        nick.total_spent += 1000;
        break;
    case 55:
        printf("Krizis syra v Zveropolise! Picca dorozhaet. +3000\n");
        nick.Nickizza.monthly_profit += 3000;
        break;
    case 56:
        printf("Den' poeta. Nick i Judy kupili rariternye zhurnaly. -6000/-2500\n");
        nick.zoobank.account -= 6000;
        nick.total_spent += 6000; 

        judy.zoobank.account -= 2500;
        judy.total_spent += 2500;
        break;
    case 57:
        printf("Remont metro. Benzin +1000\n");
        judy.car.gas += 1000;

        nick.car.gas += 1000;
        break;
    case 58:
        printf("Besplatnoe morozhenoe. Eda -500\n");
        judy.food -= 500;

        nick.food -= 500;
        break;
    case 59:
        printf("Slon v piccerii slomal dveri. -2000 RUB\n");
        nick.zoobank.account -= 2000;
        nick.total_spent += 2000;
        break;
    case 60:
        printf("Nick sdal Judy vora poka on obedal. Premiya oboim +2000\n");
        judy.zoobank.account += 2000;
        judy.total_earned += 2000; 
        break;
    case 61:
        printf("Shtorm v tropikakh. Eda +5%%\n"); 
        judy.food *= 1.05;

        nick.food *= 1.05;
        break;
    case 62:
        printf("Nick vyigral Judy v kosti. +12000 RUB\n"); 
        nick.zoobank.account += 12000;
        nick.total_earned += 12000;

        judy.zoobank.account -= 12000;
        judy.total_spent += 12000;
        break;
    case 63: 
        printf("Obnovlenie raciy Judy. +1500 RUB\n");
        judy.zoobank.account += 1500;
        judy.total_earned += 1500;
        break;
    case 64:
        printf("Zabastovka lenivcev. Probki. -3000\n"); 
        nick.zoobank.account -= 3000;
        nick.total_spent += 3000;

        judy.zoobank.account -= 3000;
        judy.total_spent += 3000;
        break;
    case 65:
        printf("Pozertvovaniya ot Mistera Biga vsem zhitelyam. +5000 RUB\n");
        nick.zoobank.account += 5000;
        nick.total_earned += 5000; 

        judy.zoobank.account += 5000;
        judy.total_earned += 5000;
        break;
    case 66:
        printf("Judy oteryala obed po puti. -2000 RUB\n");
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000; 
        break;
    case 67:
        printf("Polomka pechi u Nicka. -10000 RUB\n");
        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        break;
    case 68:
        printf("Lapo-ledency idut na ura! +8000/-250 RUB\n");
        nick.zoobank.account += 8000;
        nick.total_earned += 8000;

        judy.zoobank.account -= 250;
        judy.total_spent += 250;
        break;
    case 69:
        printf("Bilet na koncert Gazelle. -15000/-10000 RUB\n");
        judy.zoobank.account -= 15000;
        judy.total_spent += 15000; 

        nick.zoobank.account -= 10000;
        nick.total_spent += 10000;
        break;
    case 70:
        printf("Nalogovaya proverka. -2000 RUB\n"); 
        judy.zoobank.account -= 2000;
        judy.total_spent += 2000;

        nick.zoobank.account -= 2000;
        nick.total_spent += 2000;
        break;
    case 71:
        printf("Taynik u Nicka v furgone. +20000 RUB\n");
        nick.zoobank.account += 20000;
        nick.total_earned += 20000;
        break;
    case 72: 
        printf("Apteki podnyali ceny. -5000 RUB\n");
        judy.zoobank.account -= 5000;
        judy.total_spent += 5000;

        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        break;
    case 73:
        printf("Morkovnyy Dzhekpot u Judy. +30000 RUB\n");
        judy.zoobank.account += 30000;
        judy.total_earned += 30000;
        break;
    case 74:
        printf("Prodleniye registracii marki. Judy pomogla. -7000 RUB\n");
        nick.zoobank.account -= 7000;
        nick.total_spent += 7000;
        break;
    case 75:
        printf("Buket roditelyam na den' sem'yi. -3000 RUB\n");
        judy.zoobank.account -= 3000;
        judy.total_spent += 3000;

        nick.zoobank.account -= 3000;
        nick.total_spent += 3000;
        break;
    case 76:
        printf("Krysy v furgone Nicka. -5000 RUB\n");
        nick.zoobank.account -= 5000;
        nick.total_spent += 5000;
        break;
    case 77:
        printf("Nick podaril novoe plat'e Judy. -12000 RUB\n");
        nick.zoobank.account -= 12000;
        nick.total_spent += 12000;
        break;
    case 78:
        printf("Prodazha shersti. +9000/+5000 RUB\n");
        nick.zoobank.account += 9000;
        nick.total_earned += 9000;

        judy.zoobank.account += 5000;
        judy.total_earned += 5000;
        break;
    case 79:
        printf("Nalog na sahar. Pribyl' -1000\n");
        nick.Nickizza.monthly_profit -= 1000;
        break;
    case 80:
        printf("Viplata vsem zhitelyam iz gosfonda. +5000 RUB\n");
        judy.zoobank.account += 5000;
        judy.total_earned += 5000;

        nick.zoobank.account += 5000;
        nick.total_earned += 5000;
        break;


    default:
        printf("V gorode vse tiho.\n");
        break;
    }
    printf("  --------------------------------------------------\n");
}


//ФУНКЦИЯ ВЗАИМОДЕЙСТВИЯ: ДЖУДИ СПАСАЕТ НИКА (cрабатывает только тогда, когда Ник в минусе. Чем больше минус, тем больше помогает Джуди.)
void judy_to_the_rescue(int month, int year) 
{
    if (nick.zoobank.account >= 0) {        //если у Ника все хорошо, Джуди просто заходит к нему иногда на пиццу
        if (month % 4 == 0) {
            printf("  [PARTNERS]: Judy zashla k Nicku na piccu. Nick ugostil ee besplatno.\n");
            nick.zoobank.account -= 500;
        }
        return;
    }

    //если баланс Ника отрицательный, Джуди помогает ему
    RUB debt = -nick.zoobank.account; //размер долга переделать в положительное число

    printf("\n  [EMERGENCY HELP]: ");

    //уровень 1: мелкая помощь
    if (debt < 20000) {        
        printf("Judy uvidela, chto Nicku ne hvataet na edu. Perevela emu 10000 RUB.\n");
        judy.zoobank.account -= 10000;
        nick.zoobank.account += 10000;
        nick.total_earned += 10000;
        judy.total_spent += 10000;    
        nick.rescue_events_count++;
    }
    //уровень 2: серьезные проблемы
    else if (debt >= 20000 && debt < 100000) {        
        printf("U Nicka bol'shie dolgi! Judy snimaet dengi s depozita, chtoby pogasit' chast'.\n");
        RUB help_sum = 35000;
        judy.zoobank.deposite -= help_sum;
        nick.zoobank.account += help_sum;
        nick.total_earned += help_sum;
        judy.total_spent += help_sum;
        nick.rescue_events_count++;
        printf("  [NICK]: 'Morkovka, ty menya spasla ot kollektorov Mistera Biga...'\n");
    }
    else if (debt >= 100000) {
        //уровень 3: катастрофа
        printf("NICK NA GRANNY BANKROTSTVA! Judy otdaet nakopleniya.\n");
        RUB critical_help = 70000;
        judy.zoobank.deposite -= critical_help;
        nick.zoobank.account += critical_help;
        nick.total_earned += critical_help;
        judy.total_spent += critical_help;
        nick.rescue_events_count++;
        printf("  [SYSTEM]: Judy spasla Nicka ot tyur'my za dolgi, no ee vklad umen'shilsya.\n");
    }

    printf("  --------------------------------------------------\n\n");
}


void shopping_mall(int month, int year) {               //покупки в магазине 2 раза в год на праздники
    if (month == 6 || month == 12) { 
        printf("  [MALL]: Holiday sales in Zootopia! :\n");

        //Ник покупает гаджеты для бизнеса
        RUB gadget_price = 12000;
        nick.zoobank.account -= gadget_price;
        nick.Nickizza.monthly_profit += 1000; // Новая печь приносит больше денег
        printf("  - Nick kupil novuyu pech'. Profit +1000\n");

        //Джуди покупает подарки родителям
        RUB gift_price = 8000;
        judy.zoobank.account -= gift_price;
        judy.total_spent += 8000;
        printf("  - Judy otpravila podarki roditelyam. -8000\n");
        printf("  --------------------------------------------------\n");
    }
}


void character_thoughts(int month, int year) {          //функция мыслей персонажей
    printf("  [LICHNYE MYSLI]:\n");

    //мысли Джуди
    printf("  Judy: ");
    if (judy.zoobank.deposite > 1000000)
        printf("'Ogo, s moimi nakopleniyami mozhno kupit' morkovnuyu fermu!'\n");
    else if (judy.zoobank.deposite < 50000)
        printf("'Nuzhno brat' bol'she smen, scheta sami sebya ne oplatyat...'\n");
    else if (month == 12)
        printf("'Skoro Novyy God, nuzhno kupit' podarki vsem 275 brat'yam i sestram.'\n");
    else
        printf("'Eshche odin den' na strazhe poryadka v Zveropolise.'\n");

    //мысли Ника
    printf("  Nick: ");
    if (nick.zoobank.account < 0)
        printf("'Esli Mister Big uznaet o dolgakh, mne kryshka... Morkovka, vyruchay!'\n");
    else if (nick.Nickizza.monthly_profit > 10000)
        printf("'Picca prodaetsya otlichno, pora rasshiryat' set'!'\n");
    else if (nick.black_market_count > 5)
        printf("'Pora zavyazyvat' s temnymidelami, poka Judy ne dohadalas'.'\n");
    else
        printf("'Hitryy lis vsegda naydet sposob zarabotat' paru monet.'\n");

    printf("  --------------------------------------------------\n");
}


void plan_wedding() {
    wedding.guests_count = 300; // Весь участок и родственники
    wedding.cafe_rent = 500000;
    wedding.rings_cost = 150000;
    wedding.travel_cost = 800000;

    printf("\n\n  [ ROMANTIC EVENT ]: Nick i Judy reshili pozhenit'sya!\n");
    printf("  --------------------------------------------------\n");
    printf("  Nick: 'Morkovka, posle vseh etih let... pora ob'edinit' nashi scheta.'\n");
    printf("  Judy: 'Nick, ya dumala ty nikogda ne sprosish! Davay poschitaem den'gi.'\n\n");

    //объединение капиталов Ника и Джуди
    RUB nick_assets = nick.zoobank.account + (RUB)(nick.zoobank.account_usd * nick.zoobank.rate_usd_rub);
    RUB judy_assets = judy.zoobank.account + judy.zoobank.deposite + (RUB)(judy.zoobank.account_usd * judy.zoobank.rate_usd_rub);
    wedding.budget = nick_assets + judy_assets;

    RUB total_cost = wedding.cafe_rent + wedding.rings_cost + wedding.travel_cost;

    printf("  [ WEDDING CALCULATION ]:\n");
    printf("  > Obshchiy kapital:     %15lld RUB\n", wedding.budget);
    printf("  > Stoimost' svad'by:    %15lld RUB\n", total_cost);
    printf("  > Arenda cafe:     %15lld RUB\n", wedding.cafe_rent);
    printf("  > Medovyy mesyats:      %15lld RUB\n", wedding.travel_cost);

    if (wedding.budget >= total_cost) {
        printf("\n  [ RESULT ]: DEN'EG HVATAET! Zveropolis gotovitsya k svad'be goda!\n");
        printf("  Mister Big prishol i podaril molodym tseluyu morkovnuyu fermu.\n");
        printf("  Shef Bogo lichno provel ceremoniyu v policeyskom uchastke.\n");
        printf("  Nick i Judy uleteli v otpusk na Mal'divi.\n");
    }
    else {
        printf("\n  [ RESULT ]: Den'eg nemnogo ne khvatilo...\n");
        printf("  Nick: 'Nichego, Morkovka, ya proверну eshche odnu sdelku!'\n");
        printf("  Judy: 'Glupyy lis... Glavnoe, chto my vmeste.'\n");
    }
    printf("  --------------------------------------------------\n\n");
}


void collect_wedding_gifts()                 //функция получения подарков на свадьбе
{             
    printf("\n  [ PODARKI OT DOROGIKH GOSTEY ]:\n");

    RUB total_gifts = 0;
    RUB current_gift = 0;
    

    // --- Полицейский участок ---

    current_gift = 50000;
    total_gifts += current_gift;
    printf("  - Shef Bogo podaril: %lld RUB na novuyu mebel'.\n", current_gift);

    current_gift = 100000;
    total_gifts += current_gift;
    printf("  - Mister Big podaril: %lld RUB.\n", current_gift);

    current_gift = 15000;
    total_gifts += current_gift;
    printf("  - Oficer Kogtyauzer podaril: %lld RUB i korobku ponchikov.\n", current_gift);

    current_gift = 8000;
    total_gifts += current_gift;
    printf("  - Oficer Del'gato peredal: %lld RUB na remni bezopasnosti.\n", current_gift);

    current_gift = 12000; 
    total_gifts += current_gift;
    printf("  - Oficer MakRokh podaril: %lld RUB na silovuyu podgotovku.\n", current_gift);

    current_gift = 7000;
    total_gifts += current_gift;
    printf("  - Oficer Volfson peredal: %lld RUB na nochnye dezhurstva.\n", current_gift);


    // --- Друзья и знакомые ---

    current_gift = 5000;
    total_gifts += current_gift;
    printf("  - Blic peredal: %lld RUB (shel polgoda).\n", current_gift);

    current_gift = 25000;
    total_gifts += current_gift;
    printf("  - Frufru podarila: %lld RUB na dizaynerskie veshchi.\n", current_gift);

    current_gift = 10000;
    total_gifts += current_gift;
    printf("  - Finnik podaril: %lld RUB (chestno zarabotannye).\n", current_gift);

    current_gift = 150000;
    total_gifts += current_gift;
    printf("  - Gazelle podarila: %lld RUB i bilety na svoy koncert.\n", current_gift);

    current_gift = 9000; 
    total_gifts += current_gift;
    printf("  - Yaks podaril: %lld RUB i natural'noe maslo.\n", current_gift);

    current_gift = 4000;
    total_gifts += current_gift;
    printf("  - Gidmayer peredal: %lld RUB na novyy furgon.\n", current_gift);


    // --- Родственники ---

    current_gift = 30000;
    total_gifts += current_gift;
    printf("  - Stu i Bonni Hopps podarili: %lld RUB ot vsey sem'i.\n", current_gift);

    current_gift = 2000;
    total_gifts += current_gift;
    printf("  - Brat Sharron peredal: %lld RUB s morkovnoy fermy.\n", current_gift);

    current_gift = 2000;
    total_gifts += current_gift;
    printf("  - Sestra Kotton podarila: %lld RUB na melochi.\n", current_gift);

    current_gift = 2500;
    total_gifts += current_gift;
    printf("  - Dyadya Terrence peredal: %lld RUB na udachu.\n", current_gift);


    // --- Прочие жители ---

    current_gift = 11000;
    total_gifts += current_gift;
    printf("  - Mer Zlatogriv podaril: %lld RUB iz fonda goroda.\n", current_gift);

    current_gift = 1000;
    total_gifts += current_gift;
    printf("  - Barshchick peredal: %lld RUB (vse chto bylo).\n", current_gift);

    current_gift = 6500;
    total_gifts += current_gift;
    printf("  - Koslov (medved') podaril: %lld RUB na okhranu.\n", current_gift);

    current_gift = 4500;
    total_gifts += current_gift;
    printf("  - Gospodin Menchas peredal: %lld RUB na chaj.\n", current_gift);

    current_gift = 5500; 
    total_gifts += current_gift;
    printf("  - Instruktorsha v akademii podarila: %lld RUB.\n", current_gift);

    current_gift = 8800;
    total_gifts += current_gift;
    printf("  - Oficiant iz cafe podaril: %lld RUB.\n", current_gift);

    current_gift = 3300;
    total_gifts += current_gift;
    printf("  - Sosedi-antilopy podarili: %lld RUB (chtoby ne shumeli).\n", current_gift);

    current_gift = 12500;
    total_gifts += current_gift;
    printf("  - Prodavec fruktov peredal: %lld RUB.\n", current_gift);

    current_gift = 9500; 
    total_gifts += current_gift;
    printf("  - Khozyain kvartiry Judy podaril: %lld RUB.\n", current_gift);


    // --- Финальный расчет ---

    nick.zoobank.account += total_gifts;
    nick.total_earned += total_gifts;       //добавляется на счет Ника как на общий после свадьбы

    printf("  --------------------------------------------------\n");
    printf("  [SYSTEM]: Vse podarki sobrany i zachisleny na schet.\n");
    printf("  ITOGO PODARENO: %lld RUB\n", total_gifts);
    printf("  --------------------------------------------------\n\n");
}



//ФУНКЦИЯ ИТОГОВОГО ОТЧЕТА ПО ВСЕМ ГОДАМ (Добавляет ~300-400 строк)

void print_final_mega_report()
{
    printf("\n\n");
    printf("---#####################################################################---\n\n");
    printf("###########################################################################\n");
    printf("##                                                                       ##\n");
    printf("##      POLICE DEPARTMENT & TAX OFFICE OF ZOOTOPIA: FINAL ARCHIVE        ##\n");
    printf("##                    PERIOD: 2026 - 2031                                ##\n");
    printf("##                                                                       ##\n");
    printf("###########################################################################\n\n");

    // --- ОТЧЕТ ДЖУДИ ХОППС ---
    printf("  .=====================================================================.\n");
    printf("  |                   LICHNOE DELO: JUDY HOPPS                          |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | STATUS:           | OFICER POLICII                                  |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | ARHIVNAYA STATISTIKA ZA 5 LET:                                      |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | Prozhito mesyatsev:             | %10d                        |\n", judy.total_months);
    printf("  | Polucheno zarplat (raz):        | %10d                        |\n", judy.salary_payments_count);
    printf("  | Zapravok avtomobilya:           | %10d                        |\n", judy.gas_payments_count);
    printf("  | Pokupok produktov:              | %10d                        |\n", judy.food_payments_count);
    printf("  | Vizitov k vrachu:               | %10d                        |\n", judy.medicine_events_count);
    printf("  | Incidentov na sluzhbe:          | %10d                        |\n", judy.police_events_count);
    printf("  | OBSHCHIY ZARABOTOK (RUB):       | %15lld RUB               |\n", judy.total_earned);
    printf("  | OBSHCHIE TRATY (RUB):           | %15lld RUB               |\n", judy.total_spent);
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | FINANSOVYE POKAZATELI NA 2031 GOD:                                  |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | Nalichnye RUB:    | %20lld RUB                        |\n", judy.zoobank.account);
    printf("  | Depozit v banke:  | %20lld RUB                        |\n", judy.zoobank.deposite);
    printf("  | Valyutnyy zapas:  | %20lld USD                        |\n", judy.zoobank.account_usd);
    printf("  | Kurs USD (itog):  | %20.2f RUB                        |\n", judy.zoobank.rate_usd_rub);

    RUB judy_total = judy.zoobank.account + judy.zoobank.deposite +
        (RUB)(judy.zoobank.account_usd * judy.zoobank.rate_usd_rub);

    printf("  | TOTAL CAPITAL:    | %20lld RUB                        |\n", judy_total);
    printf("  | REZULTAT:         | %-35s             |\n", (judy_total > 5000000 ? "BOGATYI KROLIK" : "CHESTNYI KOP"));
    printf("  '====================================================================='\n\n");

    // --- ОТЧЕТ НИКА УАЙЛДА ---
    printf("  .=====================================================================.\n");
    printf("  |                   LICHNOE DELO: NICK WILDE                          |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | STATUS:           | VLADELEC PICCERII / ULICHNYI LIS                |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | ARHIVNAYA STATISTIKA ZA 5 LET:                                      |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | Rabochikh smen v piccerii:      | %10d                        |\n", nick.business_events_count);
    printf("  | Sdelok na chernom rynke:        | %10d                        |\n", nick.black_market_count);
    printf("  | Polucheno shtrafov (vsego):     | %10d                        |\n", nick.fines_count);
    printf("  | Platezhey po kreditu:           | %10d                        |\n", nick.loan_payments_count);
    printf("  | Spaseno morkovkoy (raz):        | %10d                        |\n", nick.rescue_events_count);
    printf("  | OBSHCHIY DOKHOD BIZNESA:        | %15lld RUB               |\n", nick.total_earned);
    printf("  | OBSHCHIE LICHNYE TRATY:         | %15lld RUB               |\n", nick.total_spent);
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | FINANSOVYE POKAZATELI NA 2031 GOD:                                  |\n");
    printf("  |---------------------------------------------------------------------|\n");
    printf("  | Nalichnye RUB:    | %20lld RUB                        |\n", nick.zoobank.account);
    printf("  | Valyuta ($):      | %20lld USD                        |\n", nick.zoobank.account_usd);
    printf("  | Pribyl' biznesa:  | %20lld RUB                        |\n", nick.Nickizza.monthly_profit);
    printf("  | Ostatok kredita:  | %20lld RUB                        |\n", nick.credit.body);
    printf("  | Summa shtrafov:   | %20lld RUB                        |\n", nick.fines);

    RUB nick_total = nick.zoobank.account + (RUB)(nick.zoobank.account_usd * nick.zoobank.rate_usd_rub) + nick.car.value;

    printf("  | TOTAL CAPITAL:    | %20lld RUB                        |\n", nick_total);
    printf("  | REZULTAT:         | %-35s             |\n", (nick.credit.body <= 0 ? "SVOBODNIY OT DOLGOV" : "VVECHNYI DOLZHNIK"));
    printf("  '====================================================================='\n\n");


    // --- СРАВНИТЕЛЬНАЯ ТАБЛИЦА ---
    printf("         [ SRAVNENIE FINANSOVOGO USPEHA PARTNEROV ]\n");
    printf(" +-----------------------+-------------------+-------------------+\n");
    printf(" | Pokazatel'            |      JUDY         |      NICK         |\n");
    printf(" +-----------------------+-------------------+-------------------+\n");
    printf(" | Final Capital (RUB)   | %17lld | %17lld |\n", judy_total, nick_total);
    printf(" | Obshchiy dokhod (RUB) | %17lld | %17lld |\n", judy.total_earned, nick.total_earned);
    printf(" | Obshchie traty (RUB)  | %17lld | %17lld |\n", judy.total_spent, nick.total_spent);
    printf(" | Kolichestvo sobytiy   | %17d | %17d |\n", judy.police_events_count, nick.business_events_count);
    printf(" | Final Capital (USD)   | %17lld | %17lld |\n", judy.zoobank.account_usd, nick.zoobank.account_usd);
    printf(" | Food Expenses (Final) | %17lld | %17lld |\n", judy.food, nick.food);
    printf(" +-----------------------+-------------------+-------------------+\n");

    if (judy_total > nick_total) {
        printf(" \n >>> REZULTAT: Judy bogache Nika na %lld RUB! (Morkovka rulez!)\n", judy_total - nick_total);
    }
    else {
        printf(" \n >>> REZULTAT: Nick bogache Judy na %lld RUB! (Lisiy biznes rascvel!)\n", nick_total - judy_total);
    }

    printf("\n ###########################################################################\n");
}


void print_official_disclaimer()                //функция описания программы (в начале работы)
{
    printf("\n\n");
    printf("  ###########################################################################\n");
    printf("  ##                                                                       ##\n");
    printf("  ##              ZOOTOPIA MULTI-AGENT ECONOMIC SYSTEM v3.0                ##\n");
    printf("  ##           OFFICIAL TECHNICAL DOCUMENTATION & TERMS OF USE             ##\n");
    printf("  ##                                                                       ##\n");
    printf("  ###########################################################################\n\n");

    printf("  1. (SYSTEM OVERVIEW):\n");
    printf("     Dannaya programma prednaznachena dlya kompleksnoy emulyacii denezhnyh\n");
    printf("     potokov v usloviyah rynochnoy ehkonomiki goroda Zveropolis.\n");
    printf("     Model' uchityvaet vliyanie makroehkonomicheskih faktorov na\n");
    printf("     mikroehkonomicheskoe sostoyanie otdel'nyh agentov (Judy i Nick).\n\n");

    printf("  2. (TERMS OF USE):\n");
    printf("     - Agent 'JUDY' deystvuet v ramkah gosudarstvennogo kontrakta.\n");
    printf("     - Agent 'NICK' yavlyaetsya sub'ektom malogo predprinimatel'stva.\n");
    printf("     - Vse raschety v RUB osushchestvlyayutsya v formate long long int.\n");
    printf("     - Konvertaciya USD proishodit po tekushchemu rynochnomu kursu.\n");
    printf("     - Nalogovye otchisleniya yavlyayutsya obyazatel'nymi dlya vseh.\n\n");

    printf("  3. (SYSTEM MODULES):\n");
    printf("     - [CORE]: Glavnyy dvizhok simulyacii (Simulation Loop).\n");
    printf("     - [ECON]: Modul' inflyacii i klyuchevoy stavki (Inflation Engine).\n");
    printf("     - [NEWS]: Generator sluchaynyh rynochnyh sobytiy (World News).\n");
    printf("     - [RESCUE]: Algoritm social'noy vzaimopomoshchi agentov.\n");
    printf("     - [BANK]: Modul' depozitnyh i kreditnyh operaciy.\n\n");

    printf("  4. (OPERATIONAL MODE):\n");
    printf("     Simulyaciya zapuskaetsya s yanvarya 2026 goda i prodolzhaetsya\n");
    printf("     do marta 2031 goda. Kazhdyy shag simulyacii raven odnomu mesyacu.\n");
    printf("     Sushchestvennye izmeneniya vnosyatsya raz v kvartal i raz v god.\n\n");

    printf("  5. (DISCLAIMER):\n");
    printf("     Razrabotchik ne neset otvetstvennosti za bankrotstvo Nika Wilde'a\n");
    printf("     v sluchae chrezmernyh trat na chernom rynke ili neudachi v biznese.\n");
    printf("     Vse sovpadeniya s real'nymi krolikami i lisami sluchayny.\n\n");

    printf("  ###########################################################################\n");
    printf("  >> SISTEMA GOTOVA K RABOTE.\n");
    printf("  >> NAZHMITE [ENTER] DLYA PODTVERZHDENIYA SOGLASIYA I ZAPUSKA...\n");
    printf("  ###########################################################################\n");

}



void simulation()                   //функция всей симуляции
{
    int month = 2;
    int year = 2026;
    RUB deposit_at_start_of_year = judy.zoobank.deposite;

    while (not (month == 3 and year == 2031)) {
        
        printf("\n>>> SYSTEM: MESYATS %02d | GOD %d <<<\n", month, year);
        printf("--------------------------------------------------\n");

        //повышение цен от инфляции, индексация зарплаты и мировые события
        inflation(month, year);
        update_currency_rate(month, year);
        world_news(month, year);
        character_thoughts(month, year);

        //--- Для Джуди ---//
         
        //счетчик месяцев
        judy.total_months++;

        //получение зарплаты и "случайные" события
        judy_salary(month, year);
        judy_police_life(month, year);

        //judy_freelance(month, year);
        
        //вычитание расходов
        judy_food();
        judy_car();

        if (month % 3 == 0) {
            judy_medine(month, year);
        }
        // my_home();

        //перевод валют
        judy_currency_exchange(month);
        //проценты и перевод остатка на депозит
        judy_deposite(month, year);


        //--- Для Ника ---//
        nick_business_logic(month, year);   //бизнес
        nick_life_events(month, year);      //те рандомные события в жизни Ника
        nick_shadow_expenses(month);        //теневые траты
        nick_expenses();            //расходы
        nick_loan_payment();        //платеж по кредиту
        nick_black_market_exchange(month, year);    //перевод валюты
        nick_law_compliance(month, year);


        judy_to_the_rescue(month, year);
        shopping_mall(month, year);

        ++month;
        if (month == 13) {
            calculate_taxes(year);
            printf("------------Year %d", year);
            printf(" Results:------------------------\n");
            printf("\n");
            printf("[JUDY STATUS]:\n");
            print_judy_report(month, year, deposit_at_start_of_year);
            printf("[NICK STATUS]:\n");
            print_nick_report(month, year);

            deposit_at_start_of_year = judy.zoobank.deposite;
            ++year;
            month = 1;
        }
    }
    print_final_mega_report();
}


//ПРОГРАММА

int main()
{
    print_official_disclaimer();

    judy_init();

    nick_init();

    simulation();

    plan_wedding();

    collect_wedding_gifts();

}