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
};

struct NickPerson {      // отдельная структура для Персонажа Ник (главная!!!)
    Bank zoobank;
    Car car;             
    Business Nickizza;   // бизнес пиццы "никицца"
    Loan credit;         // долги банку/Джуди
    RUB food;
    RUB fines;           // штрафы от полиции 
};
struct Person judy;             //Создание Персонажа Джуди;
struct NickPerson nick;             //Создание Персонажа Ник;


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
}


void nick_init()
{
    //банковские счета
    nick.zoobank.account = 50'000;
    nick.zoobank.deposite = 0;
    nick.zoobank.interest = 0;

    nick.zoobank.rate_usd_rub = 78.5;

    //машина (старая развалюха)
    nick.car.value = 400'000;
    nick.car.gas = 10'000;

    //расходы на еду
    nick.food = 15'000;

    //бизнес "Никицца"
    nick.Nickizza.investment = 200'000;
    nick.Nickizza.monthly_profit = 40'000;       //базовая прибыль
    nick.Nickizza.risk_factor = 0.3;             //30% шанс на неудачу

    //кредит (на бизнес)
    nick.credit.body = 300'000;
    nick.credit.interest = 18.0;         //высокий процент по кредиту (18%)
    nick.credit.months_left = 36;        //кредит на 3 года
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


//НИК

void nick_business_logic(const int month, const int year)         //Ник зарабатывает на пицце
{
    // можно добавить rand() для изменения прибыли
    nick.zoobank.account += nick.Nickizza.monthly_profit;
}


void nick_loan_payment()
{
    if (nick.credit.months_left > 0) {
        RUB monthly_payment = (nick.credit.body / 36) + (RUB)(nick.credit.body * (nick.credit.interest / 100 / 12));    //ежемесячный платеж

        nick.zoobank.account -= monthly_payment;
        nick.credit.months_left--;

        //усли денег не хватило, банк начисляет штраф, а долг растет
        if (nick.zoobank.account < 0) {
            nick.credit.body += 5000;
            printf("WARNING: Nick missed a loan payment in month %d!\n", nick.credit.months_left);
        }
    }
}


void nick_expenses()        //расходы Ника
{
    nick.zoobank.account -= nick.food;
    nick.zoobank.account -= nick.car.gas;
}


void nick_black_market_exchange(int month, int year)            //черный рынок обмена валют (для Ника) 
{
    if (nick.zoobank.account > 20000 && month % 4 == 0) {       //Ник пытается провернуть сделку, если у него больше 20000 рублей на счету
        int risk = (month * year) % 10;

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
            nick.zoobank.account -= penalty;
            printf("PROVAL! Nik natknulsya na moshennikov. Poteryano %lld RUB.\n", penalty);
        }
    }
}


// ОГРОМНАЯ ФУНКЦИЯ ЖИЗНЕННЫХ СОБЫТИЙ НИКА УАЙЛДА (имитирует хаотичную жизнь в Зверополисе, события влияют на баланс, бизнес или текущие расходы)

void nick_life_events(int month, int year) 
{

    int event_id = (month * 17 + year * 3) % 40;    //другая формула (не как у Джуди) для выбора события (без использования rand()), имитирует "случайные" события

    printf("  [NICK STORY]: ");

    switch (event_id) {
    case 0:
        printf("Nick prodal partiyu 'Lapo-ledentsov' slonam. +15000 RUB\n");
        nick.zoobank.account += 15000;
        break;
    case 1:
        printf("Noviy kontrakt s Politehom na postavku picci. +4000 RUB\n");
        nick.Nickizza.monthly_profit += 4000;
        break;
    case 2:
        printf("Mister Big prigrozil za starye dolgi. Prishlos' otdat' 'protsent za uvazhenie'. -12000 RUB\n");
        nick.zoobank.account -= 12000;
        break;
    case 3:
        printf("Judy pomogla zakryt' shtrafy Nicka po staroy druzhbe. +5000 RUB\n");
        nick.zoobank.account += 5000;
        break;
    case 4:
        printf("Nick nashel skidku na syr dlya pitstsy. Pribyl' 'Nickiccy' rastet!\n");
        nick.Nickizza.monthly_profit += 2000;
        break;
    case 5:
        printf("Furgon slomalsya pryamo posredi dorogi. Srochnyy remont dvigatelya. -25000 RUB\n");
        nick.zoobank.account -= 25000;
        break;
    case 6:
        printf("Nick pereprodal bilet v operu baranu-mafiose. +8500 RUB\n");
        nick.zoobank.account += 8500;
        break;
    case 7:
        printf("Nalogovaya inspektsiya proverila scheta 'Nickiccy'. Prishlos' zaplatit' nalog. -15000 RUB\n");
        nick.zoobank.account -= 15000;
        break;
    case 8:
        printf("Vypala nevidannaya udacha v ulichnuyu lotereyu 'Hvost Udachi'! +10000 RUB\n");
        nick.zoobank.account += 10000;
        break;
    case 9:
        printf("Nick kupil novyy dorogoy galstuk dlya vstrechi s investorami. -4500 RUB\n");
        nick.zoobank.account -= 4500;
        break;
    case 10:
        printf("doch' Mistera Biga stala postoyannym klientom. Pribyl' rastet! +5000 RUB\n");
        nick.Nickizza.monthly_profit += 5000;
        break;
    case 11:
        printf("Nick reshil s'ekonomit' na nalogakh, no ego poimali. Shtraf! -20000 RUB\n");
        nick.zoobank.account -= 20000;
        break;
    case 12:
        printf("Vygodnyy obmen valyuty u podpol'nykh dilerov v ruyone Tundratown. +1000 USD\n");
        nick.zoobank.account_usd += 1000;
        break;
    case 13:
        printf("Nick kupil stil'nye ochki, chtoby vyglyadet' solidnee. -7000 RUB\n");
        nick.zoobank.account -= 7000;
        break;
    case 14:
        printf("Sosedi pozhalovalis' na shum ot pechi dlya pitstsy. Vzyatka inspektoru. -5000 RUB\n");
        nick.zoobank.account -= 5000;
        break;
    case 15:
        printf("Judy zabyla obed, i Nick ugostil ee koronnoiy pitstsey. -1000 RUB.\n");
        nick.zoobank.account -= 1000;
        break;
    case 16:
        printf("Nick nashel novogo postavshchika muki. Zatraty snizilis'.\n");
        nick.Nickizza.monthly_profit += 3000;
        break;
    case 17:
        printf("Vystavka malogo biznesa v Zveropolise. Nick poluchil pochetnyy grant! +40000 RUB\n");
        nick.zoobank.account += 40000;
        break;
    case 18:
        printf("Kto-to skrutil zerkala s furgona Nicka noch'yu. -4000 RUB\n");
        nick.zoobank.account -= 4000;
        break;
    case 19:
        printf("Glavnyy povar 'Nickiccy' ushel v otpusk. Ubytki. -6000 RUB\n");
        nick.zoobank.account -= 6000;
        break;
    case 20:
        printf("Nick zaregistriroval novyy brend 'Wild Pizza'. Investitsii v marketing. -15000 RUB\n");
        nick.Nickizza.investment += 15000;
        break;
    case 21:
        printf("Krysha garazha protekla vo vremya dozhdya. Nuzhen remont. -5000 RUB\n");
        nick.zoobank.account -= 5000;
        break;
    case 22:
        printf("Selfi Nicka s pitstsey stalo virusnym v setyakh. Reklama! +10000 RUB\n");
        nick.zoobank.account += 10000;
        break;
    case 23:
        printf("Nick popal v probku iz-za lenivtsev. Opovzdal na vazhnuyu sdelku. -3000 RUB\n");
        nick.zoobank.account -= 3000;
        break;
    case 24:
        printf("Mister Big podaril Nicku staryy antikvarnyy shkaf. Tam byl tayNick! +25000 RUB\n");
        nick.zoobank.account += 25000;
        break;
    case 25:
        printf("Zabastovka fermerov. Produkty dlya lichnoy zhizni podorozhali. -4000 RUB\n");
        nick.food += 4000;
        break;
    case 26:
        printf("Nick vyigral v kosti u odnogo upyortogo barana. +15000 RUB\n");
        nick.zoobank.account += 15000;
        break;
    case 27:
        printf("Nochnoe ograblenie furgona! Vorishki vskryli seyf. -12000 RUB\n");
        nick.zoobank.account -= 12000;
        break;
    case 28:
        printf("Nick reshil stat' fud-blogerom i kupil doroguyu kameru. -30000 RUB\n");
        nick.zoobank.account -= 30000;
        break;
    case 29:
        printf("Bol'shoy zakaz dlya morskikh svinok. 100 mini-pitsts! +10000 RUB\n");
        nick.zoobank.account += 10000;
        break;
    case 30:
        printf("Nick nashel na svalke rariternuyu zapchast' i prodal ee kollektsioneru. +7000 RUB\n");
        nick.zoobank.account += 7000;
        break;
    case 31:
        printf("Odin iz kuryerov Nicka poteryal sumku s den'gami. -5000 RUB\n");
        nick.zoobank.account -= 5000;
        break;
    case 32:
        printf("Nick organizoval ulichnyy kvest dlya turistov. +9000 RUB\n");
        nick.zoobank.account += 9000;
        break;
    case 33:
        printf("Kholodil'nik v 'Nickicce' vyshel iz stroya. Produkty isportilis'. -8000 RUB\n");
        nick.zoobank.account -= 8000;
        break;
    case 34:
        printf("Nick sluchayno pomog staromu slonu pereyti dorogu. Poluchil chaevye. +1000 RUB\n");
        nick.zoobank.account += 1000;
        break;
    case 35:
        printf("Vstretil Blica na pochte. Poteryal ves' den' v ocheredi. Business prostoial. -3000 RUB\n");
        nick.zoobank.account -= 3000;
        break;
    case 36:
        printf("Pomyal bamper na furgone ob klumbu. -4000 RUB\n");
        nick.zoobank.account -= 4000;
        break;
    default:
        printf("Obychnyy mesyac' ulichnogo lisa. Nichego ne proishodilo.\n");
        break;
    }
}


void print_nick_report(int month, int year)             //вывод результатов Ника
{               
    printf("\n  _______________________________________________________  \n");
    printf(" /                                                       \\ \n");
    printf("|   DELISHKI NickA UAYLDA (BUSINESS LOG)                   |\n");
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
}


void judy_food()                            //функция еды Джуди
{
    judy.zoobank.account -= judy.food;
}


void judy_car()                             //функция машины Джуди
{
    judy.zoobank.account -= judy.car.gas;
}


// Вспомогательные функции для будущего расширения 
void judy_medine();
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

    judy.zoobank.deposite += judy.zoobank.account;
    judy.zoobank.account = 0;
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

            printf("  [ZPD BANK]: Operaciya obmena. Kupleno %lld USD s komissiey 5%%.\n", bought_usd);
        }
    }
}


// ОГРОМНАЯ ФУНКЦИЯ СЛУЖБЫ В ПОЛИЦИИ ДЖУДИ ХОППС (описывает рабочие смены, премии, выезды и расходы на службу)
void judy_police_life(int month, int year) 
{
    
    int duty_id = (month * 11 + year * 5) % 40;     //просто формула для выбора события (без использования rand()), имитирует "случайные" события
    printf("  [JUDY POLICE DUTY]: ");

    switch (duty_id) {
    case 0:
        printf("Judy vistupila s lekciey v Polytehe. Respect + 2000 RUB\n");
        judy.zoobank.account += 2000;
        break;
    case 1:
        printf("Celyy den' na postu pod dozhdem. Kupila goryachiy chaj i lekarstva. -1500 RUB\n");
        judy.zoobank.account -= 1500;
        break;
    case 2:
        printf("Uspeshno rascryto delo o propazhe zebry. Blagodarnost' ot Shefa Bogo.\n");
        break;
    case 3:
        printf("Judy sluchaino razbila raciyu. Vychet iz zarplaty. -3000 RUB\n");
        judy.zoobank.account -= 3000;
        break;
    case 4:
        printf("Kupila ogromnuyu korobku ponchikov dlya Kogtyauzera. -2000 RUB\n");
        judy.zoobank.account -= 2000;
        break;
    case 5:
        printf("Nochnoe dezhurstvo v Tundratoune. Nadbavka za nochnye smeny. +4000 RUB\n");
        judy.zoobank.account += 4000;
        break;
    case 6:
        printf("Judy kupila novye krossovki. -6000 RUB\n");
        judy.zoobank.account -= 6000;
        break;
    case 7:
        printf("Pobeda v konkurse 'Luchshiy policeyskiy mesyaca'. Gran-pri! +15000 RUB\n");
        judy.zoobank.account += 15000;
        break;
    case 8:
        printf("Zapravila sluzhebnyy motocikl za svoy schet po oshibke. -2500 RUB\n");
        judy.zoobank.account -= 2500;
        break;
    case 9:
        printf("Pomogla pozhiloy slonikhe nayti dorogu. Poluchila morkovnyy pirog (ekonomiya na ede). +1000 RUB\n");
        judy.zoobank.account += 1000;
        break;
    case 10:
        printf("Uchastie v specoperacii v tropicheskom rayone. Komandirovochnye. +7000 RUB\n");
        judy.zoobank.account += 7000;
        break;
    case 11:
        printf("Judy vyvernula lapu pri zaderzhanii. Platnaya klinika. -4500 RUB\n");
        judy.zoobank.account -= 4500;
        break;
    case 12:
        printf("Shtraf za prevyshenie skorosti na sluzhebnom avto. -2000 RUB\n");
        judy.zoobank.account -= 2000;
        break;
    case 13:
        printf("Podarok dlya roditeley. Otpravila posylku. -5000 RUB\n");
        judy.zoobank.account -= 5000;
        break;
    case 14:
        printf("Denezhnyy perevod ot roditeley. +3500 RUB\n");
        judy.zoobank.account += 3500;
        break;
    case 15:
        printf("Kupila novyy fonarik dlya osmotra temnykh pereulkov. -1200 RUB\n");
        judy.zoobank.account -= 1200;
        break;
    case 16:
        printf("Zaderzhala bandu morkovnykh vorov. Gorodskaya nagrada! +10000 RUB\n");
        judy.zoobank.account += 10000;
        break;
    case 17:
        printf("Sluzhebnoe obuchenie ekstremal'nomu vozhdeniyu.\n");
        break;
    case 18:
        printf("Poteryala kvitanciyu na vyplatu strahovki. Ubytki. -3000 RUB\n");
        judy.zoobank.account -= 3000;
        break;
    case 19:
        printf("Obed s Merom Zlatogrivym. Prishlos' sootvetstvovat' dress-kodu. -8000 RUB\n");
        judy.zoobank.account -= 8000;
        break;
    case 20:
        printf("Sdala examen v policii na otlichno. Povyshenie klassnosti! +2000 RUB k okladu.\n");
        judy.salary += 2000;
        break;
    case 21:
        printf("Zabyla vyklyuchit' mayachok, sel akkumulyator. Remont. -2500 RUB\n");
        judy.zoobank.account -= 2500;
        break;
    case 22:
        printf("Blagotvoritel'nyy marafon policii. Pozhertvovanie. -1500 RUB\n");
        judy.zoobank.account -= 1500;
        break;
    case 23:
        printf("Judy nashla uliku v starom dele. Dosrochnaya premiya. +6000 RUB\n");
        judy.zoobank.account += 6000;
        break;
    case 24:
        printf("Sluzhebnaya forma porvalas'. Novyy komplekt. -4000 RUB\n");
        judy.zoobank.account -= 4000;
        break;
    case 25:
        printf("Den' otkrytykh dverey v policii. Kupila vozdushnye shary dlya detey. -1000 RUB\n");
        judy.zoobank.account -= 1000;
        break;
    case 26:
        printf("Vypolnila plan po shtrafam za mesyac. Bonus ot departamenta. +5000 RUB\n");
        judy.zoobank.account += 5000;
        break;
    case 27:
        printf("Popytka podkupa! Judy chestnaya, no prishlos' pisat' otchety ves' den'.\n");
        break;
    case 28:
        printf("Kupila morkovnyy sok dlya vsey smeny. Podnyala boevoy duh. -2000 RUB\n");
        judy.zoobank.account -= 2000;
        break;
    case 29:
        printf("Zaderzhanie opasnogo prestupnika. Riskovye vyplaty. +12000 RUB\n");
        judy.zoobank.account += 12000;
        break;
    case 30:
        printf("Remont sluzhebnoiy mashiny posle tarana. Chastichnaya oplata. -7000 RUB\n");
        judy.zoobank.account -= 7000;
        break;
    case 31:
        printf("Judy priglashena lektorom v akademiyu. Gonorar. +8000 RUB\n");
        judy.zoobank.account += 8000;
        break;
    case 32:
        printf("Poteryala lyubimuyu ruchku-morkovku s diktofonom. Novaya stoit dorogo. -3000 RUB\n");
        judy.zoobank.account -= 3000;
        break;
    case 33:
        printf("Prorvalo trubu v kvartire. Prishlos' spat' v otele. -4500 RUB\n");
        judy.zoobank.account -= 4500;
        break;
    case 34:
        printf("Judy nashla poteryannyy koshelek i vernula vladel'cu. Nakladnye raskhody. -500 RUB\n");
        judy.zoobank.account -= 500;
        break;
    case 35:
        printf("Judy poimala vora sumochek. Premiya! +5000 RUB\n");
        judy.zoobank.account += 5000;
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


void simulation()                   //функция всей симуляции
{
    int month = 2;
    int year = 2026;
    RUB deposit_at_start_of_year = judy.zoobank.deposite;

    while (not (month == 3 and year == 2031)) {

        //повышение цен от инфляции и индексация зарплаты
        inflation(month, year);


        //--- Для Джуди ---//
        
        //получение зарплаты и "случайные" события
        judy_salary(month, year);
        judy_police_life(month, year);

        //judy_freelance(month, year);
        
        //вычитание расходов
        judy_food();
        judy_car();
        //
        // my_cat();
        // my_medine();
        // my_home();

        //проценты и перевод остатка на депозит
        judy_deposite(month, year);


        //--- Для Ника ---//
        nick_life_events(month, year);  //те рандомные события в жизни Ника
        nick_business_logic(month, year);
        nick_expenses();
        nick_loan_payment();


        ++month;
        if (month == 13) {
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
}


//ПРОГРАММА

int main()
{
    judy_init();

    nick_init();

    simulation();

}
