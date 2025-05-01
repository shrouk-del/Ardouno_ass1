[![images-3.jpg](https://i.postimg.cc/D0VVTFBt/images-3.jpg)](https://postimg.cc/qhGDcffL)
# الكود:
cpp
#include <LiquidCrystal_I2C.h>

int redLED = 8;
int yellowLED = 7;
int greenLED = 6;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();  
}

void loop() {
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  lcd.clear(); 
  lcd.setCursor(0, 0); 
  lcd.print("STOP"); 
  delay(5000); 

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GET READY"); 
  delay(2000); 

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WALK"); 
  delay(5000); 
}


---

### الشرح :

#### *أول حاجة: إحنا جايبين إيه؟*
- #include <LiquidCrystal_I2C.h>: دي زي ما تكون مكتبة في المدرسة، فيها كل التعليمات اللي هتخلّي شاشة الـ LCD تشتغل. من غيرها، الشاشة مش هتعرف إزاي تتكلم مع الأردوينو.
- int redLED = 8;, yellowLED = 7;, greenLED = 6;: هنا إحنا بنقول للأردوينو إن اللمبة الحمرا متوصلة في البنّة (Pin) رقم 8، الصفرا في 7، والخضرا في 6. زي ما تكون بتعرّف الناس في الشارع: دي لمبة التوقف، دي للاستعداد، ودي للسير.
- LiquidCrystal_I2C lcd(0x27, 16, 2);: هنا بنقول للأردوينو إن عندنا شاشة LCD، عنوانها 0x27 (زي رقم بيتها)، وهي 16 خانة في الطول و2 سطر في العرض.

---

#### **الجزء اللي اسمه setup(): بنجهّز العدّة**
- void setup(): دي الجزئية اللي بتشتغل مرة واحدة بس لما تضغط تشغيل على الأردوينو، زي لما بتفتح المحل الصبح وتظبّط كل حاجة.
- pinMode(redLED, OUTPUT);, pinMode(yellowLED, OUTPUT);, pinMode(greenLED, OUTPUT);: هنا بنقول للأردوينو إن الـ Pins 8 و7 و6 هيبقوا مخرجات، يعني هيطلّعوا كهربا عشان يشغلوا اللمبات (مش هيستقبلوا إشارات).
- lcd.begin(16, 2);: بنقول للشاشة: "يلا، استعدي، إنتِ شاشة 16×2، ابدأي شغلك!" عشان تعرف تشتغل كويس.
- lcd.backlight();: بنور الضوء اللي ورا الشاشة عشان الكلام يبان، زي لما تنوّر لمبة في أوضة عشان تشوف.

---

#### **الجزء اللي اسمه loop(): الشغل اللي بيحصل كل شوية**
- void loop(): دي الجزئية اللي بتفضل تتكرر طول ما الأردوينو شغال، زي ما الإشارة في الشارع بتفضل تشتغل (حمرا، صفرا، خضرا) على طول.
- *أول حاجة: اللمبة الحمرا*:
  - digitalWrite(redLED, HIGH);: بنقول للأردوينو: "شغّل اللمبة الحمرا!" يعني الكهربا بتوصلها وتنور.
  - digitalWrite(yellowLED, LOW);, digitalWrite(greenLED, LOW);: بنطفّي الصفرا والخضرا عشان بس الحمرا اللي تنور.
  - lcd.clear();: بنمسح أي كلام قديم على الشاشة، زي ما تمسح السبورة قبل ما تكتب حاجة جديدة.
  - lcd.setCursor(0, 0);: بنقول للشاشة: "اكتبي الكلام من أول السطر الأولاني، من أول خانة."
  - lcd.print("STOP");: بنكتب "STOP" على الشاشة، يعني بنقول للمشاة: "قف، ما تعبرش دلوقتي!"
  - delay(5000);: بنستنّى 5 ثواني (5000 ميللي ثانية)، يعني اللمبة الحمرا والكلام على الشاشة هيفضلوا 5 ثواني.
- *تاني حاجة: اللمبة الصفرا*:
  - digitalWrite(redLED, LOW);: بنطفّي الحمرا.
  - digitalWrite(yellowLED, HIGH);: بنشغّل الصفرا.
  - digitalWrite(greenLED, LOW);: الخضرا لسه مطفية.
  - lcd.clear();: بنمسح الشاشة تاني.
  - lcd.setCursor(0, 0);: بنرجّع الكتابة من أول السطر الأولاني.
  - lcd.print("GET READY");: بنكتب "GET READY"، يعني بنقول للمشاة: "استعد، قرّب تعبر!"
  - delay(2000);: بنستنّى ثانيتين بس، عشان الصفرا مابتطولش زي الحمرا والخضرا.
- *تالت حاجة: اللمبة الخضرا*:
  - digitalWrite(redLED, LOW);, digitalWrite(yellowLED, LOW);: بنطفّي الحمرا والصفرا.
  - digitalWrite(greenLED, HIGH);: بنشغّل الخضرا.
  - lcd.clear();: بنمسح الشاشة.
  - lcd.setCursor(0, 0);: بنكتب من أول السطر الأولاني.
  - lcd.print("WALK");: بنكتب "WALK"، يعني بنقول للمشاة: "يلا، اعبر بسرعة!"
  - delay(5000);: بنستنّى 5 ثواني، والخضرا والكلام هيفضلوا شغّالين.

---

### *إزاي الكود ده بيشتغل؟*
- الأردوينو بيشتغل زي إشارة الطريق الحقيقية:
  1. الأول يشغّل اللمبة الحمرا ويكتب "STOP" على الشاشة، يستنّى 5 ثواني (يعني العربيات واقفة والمشاة ما يعبروش).
  2. بعدين يطفّي الحمرا ويشغّل الصفرا ويكتب "GET READY"، يستنّى ثانيتين (يعني جهّز نفسك، الإشارة هتتغيّر).
  3. بعدين يطفّي الصفرا ويشغّل الخضرا ويكتب "WALK"، يستنّى 5 ثواني (يعني المشاة يعبروا والعربيات واقفة).
- وبعد ما يخلّص الخضرا، يرجع من الأول تاني (حمرا، صفرا، خضرا) وكده دواليك، عشان الإشارة تفضل شغالة.

---

### *لو فيه مشكلة؟*
- *الشاشة ما نورتش؟*:
  - ممكن عنوان الشاشة (اللي كتبناه 0x27) يبقى غلط. جرب غيّره لـ 0x3F في السطر LiquidCrystal_I2C lcd(0x27, 16, 2);.
  - أو تكون الدايرة موصلتش صح، راجع إن SDA متوصل بـ A4 وSCL بـ A5، وVCC بـ 5V وGND بـ GND.
- *الكود م اشتغلش؟*:
  - لو في Wokwi، المكتبة LiquidCrystal_I2C موجودة جاهزة، بس لو بتشتغل على أردوينو حقيقي، لازم تنزل المكتبة بنفسك.
