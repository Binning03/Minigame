#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include<vector>
#include<cstdlib>
#include <fstream>
#include<time.h>
#include <random>

using namespace std;
using namespace sf;
#define WIDTH 1280
#define HEIGHT 800

//game 3
#define KEYPAD_START_X          0
#define KEYPAD_START_Y          0
#define KEYPAD_BTN_WIDTH        640
#define KEYPAD_BTN_HEIGHT       400


string com_numbers = "";
int level = 1;

int generate_random_number() { // 난수 만들기
    com_numbers.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 3);
    for (int i = 0; i < level; i++) com_numbers += to_string(dis(gen));
#if 0
    cout << "-----------------------------------------" << endl;
    cout << "[COM]Level:" << level << " Random Number:" << comNumbers << endl;
    cout << "-----------------------------------------" << endl;
#endif
    return 0;
}

//game 4
int num4; // 확률
int high_level = 0;
vector<Sprite> tier; //main 함수 폭파 방지용 전역변수 선언
void randint() { // 난수 만들기
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    num4 = dis(gen);
}

int textSetting(Text& textMsg, Font& font, int size,
    float x, float y, const Color& color, const Color& outColor, string s)
{
    textMsg.setFont(font);             //폰트
    textMsg.setCharacterSize(size);    //크기 
    textMsg.setPosition(x, y);         //x, y 위치
    textMsg.setFillColor(color);       //색
    textMsg.setOutlineColor(outColor); //글자 테두리 색
    textMsg.setOutlineThickness(1.f);  //글자 테두리 굵기
    textMsg.setString(s); //출력할 문자열

    return 0;
}

int main()
{
    //max score
    ifstream file("score.txt");
    string s1, s2, s3, s4;
    getline(file, s1);
    getline(file, s2);
    getline(file, s3);
    getline(file, s4);
    file.close();

    srand(time(NULL));
    RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Mini Game World");
    window.setFramerateLimit(60);

    //minigame main
    Texture minigameback;
    minigameback.loadFromFile("images/minigame.png");
    Sprite minigameground(minigameback);

    //over
    Texture overback;
    overback.loadFromFile("images/gameover.png");
    Sprite overground(overback);

    //Text Font
    Font font;
    font.loadFromFile("FreeFont.ttf");

    //------------------------1번게임---------------------------
    //main
    Texture mainback1;
    mainback1.loadFromFile("images/game1/main.png");
    Sprite mainground1(mainback1);

    //background
    Texture back1;
    back1.loadFromFile("images/game1/back.png");
    Sprite background1(back1);

    //obstacle
    vector<Sprite> obstacle1s;
    Texture obstacle1Tex;
    Sprite obstacle1;
    obstacle1Tex.loadFromFile("images/game1/obstacle1.png");
    obstacle1.setTexture(obstacle1Tex);
    obstacle1s.push_back(Sprite(obstacle1));
    int obstacle1SpawnTimer = 10;
    vector<Sprite> obstacle2s;
    Texture obstacle2Tex;
    Sprite obstacle2;
    obstacle2Tex.loadFromFile("images/game1/obstacle2.png");
    obstacle2.setTexture(obstacle2Tex);
    obstacle2s.push_back(Sprite(obstacle2));
    int obstacle2SpawnTimer = 10;

    //items
    Texture heartTex;
    Sprite heart;
    heartTex.loadFromFile("images/game1/heart.png");
    heart.setTexture(heartTex);
    Texture bombTex;
    Sprite bomb;
    bombTex.loadFromFile("images/game1/bomb.png");
    bomb.setTexture(bombTex);
    Texture sandTex;
    Sprite sand;
    sandTex.loadFromFile("images/game1/sand.png");
    sand.setTexture(sandTex);
    bool sandclock;
    int sandclockTime = 0;
    int sandSpawnTimer;
    int bombSpawnTimer;
    int heartSpawnTimer;
    int x = rand();
    if (x % 3 == 0) {
        sandSpawnTimer = 600;
        bombSpawnTimer = 300;
        heartSpawnTimer = 0;
    }
    else if (x % 3 == 1) {
        sandSpawnTimer = 300;
        bombSpawnTimer = 0;
        heartSpawnTimer = 600;
    }
    else if (x % 3 == 2) {
        sandSpawnTimer = 0;
        bombSpawnTimer = 600;
        heartSpawnTimer = 300;
    }

    //bird
    Texture birdTex;
    Sprite bird;
    int hp = 10;
    birdTex.loadFromFile("images/game1/bird.png");
    bird.setTexture(birdTex);

    // hp
    RectangleShape hp_s;
    hp_s.setSize(Vector2f(50, 50));
    hp_s.setFillColor(Color::Red);

    vector<RectangleShape> hp_ss;
    for (size_t i = 0; i < 10; i++) {
        hp_s.setPosition(Vector2f((window.getSize().x / 2) - 150 + (i * 30), 0));
        hp_ss.push_back(RectangleShape(hp_s));
    }

    //score
    Text text1;
    string msg1 = "Max\nScore\n: " + s1;
    textSetting(text1, font, 60, 55, 70, Color::Black, Color::White, msg1);

    //------------------------1번게임---------------------------

    //------------------------2번게임---------------------------
    //main
    Texture mainback2;
    mainback2.loadFromFile("images/game2/main.png");
    Sprite mainground2(mainback2);

    //background
    Texture back2;
    back2.loadFromFile("images/game2/background.png");
    Sprite background2(back2);

    //person
    Texture magicianTex;
    magicianTex.loadFromFile("images/game2/magician.png");
    Sprite magician(magicianTex);
    magician.setPosition((window.getSize().x / 2) - 85, (window.getSize().y / 2) - 85);
    int hp2 = 3;
    Texture heart2;
    heart2.loadFromFile("images/game2/heart.png");
    vector<Sprite> hp_s2;
    for (int i = 0; i < 3; i++) {
        hp_s2.push_back(Sprite(heart2));
    }
    hp_s2[0].setPosition(0, 0);
    hp_s2[1].setPosition(100, 0);
    hp_s2[2].setPosition(200, 0);
    Texture effectTex;
    effectTex.loadFromFile("images/game2/effect.png");
    Sprite effect(effectTex);
    vector<pair<Sprite, int>> effects;

    //ufo
    Texture upufo;
    upufo.loadFromFile("images/game2/ufoup.png");
    Sprite ufoup(upufo);
    Texture leftufo;
    leftufo.loadFromFile("images/game2/ufoleft.png");
    Sprite ufoleft(leftufo);
    Texture rightufo;
    rightufo.loadFromFile("images/game2/uforight.png");
    Sprite uforight(rightufo);
    Texture downufo;
    downufo.loadFromFile("images/game2/ufodown.png");
    Sprite ufodown(downufo);
    vector<Sprite> up;
    vector<Sprite> down;
    vector<Sprite> right;
    vector<Sprite> left;

    int enemySpawnTimer = 12;
    int enemySpeed = 1;
    int speedup = 0;
    bool magickey = true;

    //score
    Text text2;
    string msg2 = "Max\nScore\n: " + s2;
    textSetting(text2, font, 60, 55, 70, Color::White, Color::Black, msg2);
    //------------------------2번게임---------------------------

    //------------------------3번게임---------------------------
    Texture tex_color_off, tex_color_on;
    Sprite sprite_off[5], sprite_on[5], sprite_start_logo;
    Font font_level, font_message;
    Text text_level, text_message;

    string input_numbers = "";
    int levelLoop = 0;

    int x3 = 0, y3 = 0, n3 = 0;
    int color_grid[2][2] = { 0 };
    int xx3 = 0, yy3 = 0;

    Clock clock3;

    float number_order = 0, delay_number_order = 1.5;  //interval for show each color
    float game_start = 0, delay_game_start = 2.0;      //wait for game start
    float ready = 0, delay_ready = 2.0;                //Show "Ready, Go" message for 2 seconds

    string level_string = "Level : " + to_string(level);
    string message_string = "Ready, Go!";
    bool isgamestart = false;
    int idx3 = 0;

    //Load resources from files
    if (tex_color_off.loadFromFile("images/game3/colors_off.png") == false)
    {
        cout << "loadFromeFile err" << endl;
        return -1;
    }

    if (tex_color_on.loadFromFile("images/game3/Alos.png") == false)
    {
        cout << "loadFromeFile err" << endl;
        return -1;
    }


    if (font_level.loadFromFile("images/game3/BinggraeMelona.ttf") == false)
    {
        cout << "loadFromeFile err" << endl;
        return -1;
    }

    if (font_message.loadFromFile("images/game3/DS-DIGIB.ttf") == false)
    {
        cout << "loadFromeFile err" << endl;
        return -1;
    }

    //Set logo
    sprite_start_logo.setTexture(tex_color_off);
    sprite_start_logo.setOrigin(sf::Vector2f(tex_color_off.getSize()) / 2.f);
    sprite_start_logo.setPosition(sprite_start_logo.getOrigin());


    textSetting(text_level, font_level, 30, 10.f, 10.f,
        Color::Black, Color::Black, level_string);
    textSetting(text_message, font_message, 30, 10.f, 50,
        Color::Black, Color::Black, message_string);

    //Init. Color pad & Color grid
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sprite_off[n3].setTexture(tex_color_off);
            sprite_off[n3].setTextureRect(IntRect(j * KEYPAD_BTN_WIDTH, i * KEYPAD_BTN_HEIGHT,
                KEYPAD_BTN_WIDTH, KEYPAD_BTN_HEIGHT));
            color_grid[i][j] = n3;

            sprite_on[n3].setTexture(tex_color_on);
            n3++;
        }
    }

    generate_random_number();

    //main
    Texture mainback3;
    mainback3.loadFromFile("images/game3/main.png");
    Sprite mainground3(mainback3);

    //background
    Texture back3;
    back3.loadFromFile("images/game3/background.png");
    Sprite background3(back3);

    Text text3;
    string msg3 = "Max\nScore\n: " + s3;
    textSetting(text3, font, 60, 55, 70, Color::Black, Color::White, msg3);

    //------------------------3번게임---------------------------

    //------------------------4번게임---------------------------
    //main
    Texture mainback4;
    mainback4.loadFromFile("images/game4/main.png");
    Sprite mainground4(mainback4);

    //background
    Texture back4;
    back4.loadFromFile("images/game4/background.png");
    Sprite background4(back4);

    Text text4;
    string msg4 = "Max\nScore\n: " + s4;
    textSetting(text4, font, 60, 55, 70, Color::Black, Color::White, msg4);

    bool key_bool = true;

    Texture good;
    good.loadFromFile("images/game4/beauty.png");
    Sprite goods(good);
    goods.setPosition((window.getSize().x / 2) - 290, (window.getSize().y / 2) - 100);

    Texture boom;
    boom.loadFromFile("images/game4/explode.png");
    Sprite booms(boom);
    booms.setPosition((window.getSize().x / 2) - 290, (window.getSize().y / 2) - 100);
    //-Bronze

    Texture tier_file1;
    tier_file1.loadFromFile("images/game4/bronze5.png");
    Sprite tier_sprite(tier_file1);
    tier.push_back(tier_sprite);

    Texture tier_file2;
    tier_file2.loadFromFile("images/game4/bronze4.png");
    Sprite tier_sprite2(tier_file2);
    tier.push_back(tier_sprite2);

    Texture tier_file3;
    tier_file3.loadFromFile("images/game4/bronze3.png");
    Sprite tier_sprite3(tier_file3);
    tier.push_back(tier_sprite3);

    Texture tier_file4;
    tier_file4.loadFromFile("images/game4/bronze2.png");
    Sprite tier_sprite4(tier_file4);
    tier.push_back(tier_sprite4);

    Texture tier_file5;
    tier_file5.loadFromFile("images/game4/bronze1.png");
    Sprite tier_sprite5(tier_file5);
    tier.push_back(tier_sprite5);

    //-Silver

    Texture tier_file6;
    tier_file6.loadFromFile("images/game4/silver5.png");
    Sprite tier_sprite6(tier_file6);
    tier.push_back(tier_sprite6);

    Texture tier_file7;
    tier_file7.loadFromFile("images/game4/silver4.png");
    Sprite tier_sprite7(tier_file7);
    tier.push_back(tier_sprite7);

    Texture tier_file8;
    tier_file8.loadFromFile("images/game4/silver3.png");
    Sprite tier_sprite8(tier_file8);
    tier.push_back(tier_sprite8);

    Texture tier_file9;
    tier_file9.loadFromFile("images/game4/silver2.png");
    Sprite tier_sprite9(tier_file9);
    tier.push_back(tier_sprite9);

    Texture tier_file10;
    tier_file10.loadFromFile("images/game4/silver1.png");
    Sprite tier_sprite10(tier_file10);
    tier.push_back(tier_sprite10);

    //-Gold

    Texture tier_file11;
    tier_file11.loadFromFile("images/game4/gold5.png");
    Sprite tier_sprite11(tier_file11);
    tier.push_back(tier_sprite11);

    Texture tier_file12;
    tier_file12.loadFromFile("images/game4/gold4.png");
    Sprite tier_sprite12(tier_file12);
    tier.push_back(tier_sprite12);

    Texture tier_file13;
    tier_file13.loadFromFile("images/game4/gold3.png");
    Sprite tier_sprite13(tier_file13);
    tier.push_back(tier_sprite13);

    Texture tier_file14;
    tier_file14.loadFromFile("images/game4/gold2.png");
    Sprite tier_sprite14(tier_file14);
    tier.push_back(tier_sprite14);

    Texture tier_file15;
    tier_file15.loadFromFile("images/game4/gold1.png");
    Sprite tier_sprite15(tier_file15);
    tier.push_back(tier_sprite15);

    //-Platinum

    Texture tier_file16;
    tier_file16.loadFromFile("images/game4/platinum5.png");
    Sprite tier_sprite16(tier_file16);
    tier.push_back(tier_sprite16);

    Texture tier_file17;
    tier_file17.loadFromFile("images/game4/platinum4.png");
    Sprite tier_sprite17(tier_file17);
    tier.push_back(tier_sprite17);

    Texture tier_file18;
    tier_file18.loadFromFile("images/game4/platinum3.png");
    Sprite tier_sprite18(tier_file18);
    tier.push_back(tier_sprite18);

    Texture tier_file19;
    tier_file19.loadFromFile("images/game4/platinum2.png");
    Sprite tier_sprite19(tier_file19);
    tier.push_back(tier_sprite19);

    Texture tier_file20;
    tier_file20.loadFromFile("images/game4/platinum1.png");
    Sprite tier_sprite20(tier_file20);
    tier.push_back(tier_sprite20);

    //-Diamond

    Texture tier_file21;
    tier_file21.loadFromFile("images/game4/diamond5.png");
    Sprite tier_sprite21(tier_file21);
    tier.push_back(tier_sprite21);

    Texture tier_file22;
    tier_file22.loadFromFile("images/game4/diamond4.png");
    Sprite tier_sprite22(tier_file22);
    tier.push_back(tier_sprite22);

    Texture tier_file23;
    tier_file23.loadFromFile("images/game4/diamond3.png");
    Sprite tier_sprite23(tier_file23);
    tier.push_back(tier_sprite23);

    Texture tier_file24;
    tier_file24.loadFromFile("images/game4/diamond2.png");
    Sprite tier_sprite24(tier_file24);
    tier.push_back(tier_sprite24);

    Texture tier_file25;
    tier_file25.loadFromFile("images/game4/diamond1.png");
    Sprite tier_sprite25(tier_file25);
    tier.push_back(tier_sprite25);

    //-Ruby

    Texture tier_file26;
    tier_file26.loadFromFile("images/game4/ruby5.png");
    Sprite tier_sprite26(tier_file26);
    tier.push_back(tier_sprite26);

    Texture tier_file27;
    tier_file27.loadFromFile("images/game4/ruby4.png");
    Sprite tier_sprite27(tier_file27);
    tier.push_back(tier_sprite27);

    Texture tier_file28;
    tier_file28.loadFromFile("images/game4/ruby3.png");
    Sprite tier_sprite28(tier_file28);
    tier.push_back(tier_sprite28);

    Texture tier_file29;
    tier_file29.loadFromFile("images/game4/ruby2.png");
    Sprite tier_sprite29(tier_file29);
    tier.push_back(tier_sprite29);

    Texture tier_file30;
    tier_file30.loadFromFile("images/game4/ruby1.png");
    Sprite tier_sprite30(tier_file30);
    tier.push_back(tier_sprite30);

    //reverse(tier.begin(), tier.end());

    for (int i = 0; i < 30; i++) {
        tier[i].setPosition((window.getSize().x / 2) - 280, (window.getSize().y / 2) + 100);
    }
    Text description;
    Text percen;
    string description_string = "Bronze 5";
    int level4 = 0;

    int success[] = { 98,96,94,92,90,86,82,78,74,70,66,62,58,54,50,46,42,38,34,30,26,22,18,14,10,8,6,4,2 };
    int fail[] = { 2,4,6,8,10,14,18,22,26,30,30,34,38,42,46,48,52,56,60,64,66,70,74,78,82,82,84,86,88 };
    //------------------------4번게임---------------------------

    cout << "미니게임천국을 시작합니다.\n";

    while (window.isOpen())
    {
        Event event3;
        while (window.pollEvent(event3))
        {
            if (event3.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::Num1) || Keyboard::isKeyPressed(Keyboard::Numpad1)) {
            cout << "Albatross Game에 접속합니다.\n";
            while (!Keyboard::isKeyPressed(Keyboard::Q)) {
                if (Keyboard::isKeyPressed(Keyboard::S)) {
                    hp = 10;
                    obstacle1s.clear();
                    obstacle2s.clear();
                    heart.setPosition(-100, 0);
                    bomb.setPosition(-100, 0);
                    sand.setPosition(-100, 0);
                    sandclock = false;
                    sandclockTime = 0;
                    int x = rand();
                    Mouse::setPosition(sf::Vector2i(10, 10), window);
                    if (x % 3 == 0) {
                        sandSpawnTimer = 600;
                        bombSpawnTimer = 300;
                        heartSpawnTimer = 0;
                    }
                    else if (x % 3 == 1) {
                        sandSpawnTimer = 300;
                        bombSpawnTimer = 0;
                        heartSpawnTimer = 600;
                    }
                    else if (x % 3 == 2) {
                        sandSpawnTimer = 0;
                        bombSpawnTimer = 600;
                        heartSpawnTimer = 300;
                    }
                    time_t start = time(NULL); //점수
                    cout << "Albatross Game을 시작합니다.\n";
                    while (!Keyboard::isKeyPressed(Keyboard::M)) {
                        // update
                        // bird (player)

                        if (hp > 0) {
                            if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) < 0 && Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) < 0) bird.setPosition(0, 0);
                            else if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) < 0 && Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) > HEIGHT - 95) bird.setPosition(0, HEIGHT - 95);
                            else if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) > WIDTH - 60 && Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) < 0) bird.setPosition(WIDTH - 60, 0);
                            else if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) > WIDTH - 60 && Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) > HEIGHT - 95) bird.setPosition(WIDTH - 60, HEIGHT - 95);
                            else if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) < 0) bird.setPosition(0, Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15)); //왼쪽초과
                            else if (Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15) > WIDTH - 60) bird.setPosition(WIDTH - 60, Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15));//오른쪽초과
                            else if (Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) < 0) bird.setPosition(Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15), 0); //위쪽초과
                            else if (Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15) > HEIGHT - 95) bird.setPosition(Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15), HEIGHT - 95); //아래쪽초과
                            else bird.setPosition(Mouse::getPosition(window).x - (bird.getLocalBounds().width * 0.15), Mouse::getPosition(window).y - (bird.getLocalBounds().height * 0.15));
                        }
                        else {
                            //점수
                            time_t end = time(NULL);
                            int x = (end - start);
                            if (x > stoi(s1)) s1 = to_string(x);
                            while (!Keyboard::isKeyPressed(Keyboard::M) && !Keyboard::isKeyPressed(Keyboard::R)) {
                                window.clear(Color::White);
                                window.draw(overground);
                                Text overtext1;
                                string overmsg1 = "Max Score : " + s1 + "\nScore : " + to_string(x);
                                textSetting(overtext1, font, 45, 400, 465, Color::White, Color::Black, overmsg1);
                                window.draw(overtext1);
                                window.display();
                            }
                            if (Keyboard::isKeyPressed(Keyboard::M)) {

                            }
                            else if (Keyboard::isKeyPressed(Keyboard::R)) {
                                obstacle1s.clear();
                                obstacle2s.clear();
                                start = time(NULL); //점수
                                hp = 10;
                                heart.setPosition(-100, 0);
                                bomb.setPosition(-100, 0);
                                sand.setPosition(-100, 0);
                                sandclock = false;
                                sandclockTime = 0;
                                int x = rand();
                                Mouse::setPosition(sf::Vector2i(10, 10), window);
                                if (x % 3 == 0) {
                                    sandSpawnTimer = 600;
                                    bombSpawnTimer = 300;
                                    heartSpawnTimer = 0;
                                }
                                else if (x % 3 == 1) {
                                    sandSpawnTimer = 300;
                                    bombSpawnTimer = 0;
                                    heartSpawnTimer = 600;
                                }
                                else if (x % 3 == 2) {
                                    sandSpawnTimer = 0;
                                    bombSpawnTimer = 600;
                                    heartSpawnTimer = 300;
                                }
                                cout << "Albatross Game을 시작합니다.\n";
                            }
                        }

                        // obstacles (enemies)
                        for (size_t i = 0; i < obstacle1s.size(); i++) {
                            if (sandclock) obstacle1s[i].move(-4, 0);
                            else obstacle1s[i].move(-8, 0);
                            if (obstacle1s[i].getPosition().x < 0 - obstacle1.getGlobalBounds().width * 0.8)
                                obstacle1s.erase(obstacle1s.begin() + i);
                        }
                        if (obstacle1SpawnTimer < 12)
                            if (!sandclock) obstacle1SpawnTimer++;
                        if (obstacle1SpawnTimer >= 12) {
                            obstacle1.setPosition(window.getSize().x, rand() % int(window.getSize().y - (obstacle1.getLocalBounds().height * 0.1)));
                            obstacle1s.push_back(Sprite(obstacle1));
                            obstacle1SpawnTimer = 0;
                        }
                        for (size_t i = 0; i < obstacle2s.size(); i++) {
                            if (sandclock) obstacle2s[i].move(-6, 0);
                            else obstacle2s[i].move(-12, 0);
                            if (obstacle2s[i].getPosition().x < 0 - obstacle2.getGlobalBounds().width * 0.8)
                                obstacle2s.erase(obstacle2s.begin() + i);
                        }
                        if (obstacle2SpawnTimer < 42)
                            if (!sandclock) obstacle2SpawnTimer++;
                        if (obstacle2SpawnTimer >= 42) {
                            obstacle2.setPosition(window.getSize().x, rand() % int(window.getSize().y - (obstacle2.getLocalBounds().height * 0.1)));
                            obstacle2s.push_back(Sprite(obstacle2));
                            obstacle2SpawnTimer = 0;
                        }

                        // collision
                        for (size_t i = 0; i < obstacle1s.size(); i++) {
                            if (bird.getGlobalBounds().intersects(obstacle1s[i].getGlobalBounds())) {
                                if (hp > 2) hp -= 2;
                                else hp = 0;
                                obstacle1s.erase(obstacle1s.begin() + i);
                                break;
                            }
                        }
                        for (size_t i = 0; i < obstacle2s.size(); i++) {
                            if (bird.getGlobalBounds().intersects(obstacle2s[i].getGlobalBounds())) {
                                if (hp > 3) hp -= 3;
                                else hp = 0;
                                obstacle2s.erase(obstacle2s.begin() + i);
                                break;
                            }
                        }

                        // item
                        if (heartSpawnTimer < 900)
                            heartSpawnTimer++;
                        if (heartSpawnTimer >= 900) {
                            heart.setPosition(rand() % int(window.getSize().x - (heart.getLocalBounds().width * 0.1)), rand() % int(window.getSize().y - (heart.getLocalBounds().height * 0.1)));
                            heartSpawnTimer = 0;
                        }
                        if (bird.getGlobalBounds().intersects(heart.getGlobalBounds())) {
                            if (hp < 10) hp += 2;
                            heart.setPosition(-100, 0);
                        }
                        if (bombSpawnTimer < 900)
                            bombSpawnTimer++;
                        if (bombSpawnTimer >= 900) {
                            bomb.setPosition(rand() % int(window.getSize().x - (bomb.getLocalBounds().width * 0.1)), rand() % int(window.getSize().y - (bomb.getLocalBounds().height * 0.1)));
                            bombSpawnTimer = 0;
                        }
                        if (bird.getGlobalBounds().intersects(bomb.getGlobalBounds())) {
                            obstacle1s.clear();
                            obstacle2s.clear();
                            bomb.setPosition(-100, 0);
                        }
                        if (sandSpawnTimer < 900)
                            sandSpawnTimer++;
                        if (sandSpawnTimer >= 900) {
                            sand.setPosition(rand() % int(window.getSize().x - (sand.getLocalBounds().width * 0.1)), rand() % int(window.getSize().y - (sand.getLocalBounds().height * 0.1)));
                            sandSpawnTimer = 0;
                        }
                        if (bird.getGlobalBounds().intersects(sand.getGlobalBounds())) {
                            sandclock = true;
                            sandclockTime = 0;
                            sand.setPosition(-100, 0);
                        }
                        if (sandclock) {
                            sandclockTime++;
                            if (sandclockTime > 100) sandclock = false;
                        }

                        // draw
                        window.clear(Color::White);
                        background1.setPosition(0, 0);
                        window.draw(background1);
                        window.draw(bird);
                        window.draw(heart);
                        window.draw(bomb);
                        window.draw(sand);

                        for (size_t i = 0; i < obstacle1s.size(); i++) {
                            window.draw(obstacle1s[i]);
                        }
                        for (size_t i = 0; i < obstacle2s.size(); i++) {
                            window.draw(obstacle2s[i]);
                        }
                        for (size_t i = 0; i < hp; i++) {
                            window.draw(hp_ss[i]);
                        }

                        window.display();
                    }
                    cout << "Albatross Game 매인화면으로 갑니다.\n";
                }
                //Albatross Game main draw
                mainground1.setPosition(0, 0);
                window.clear(Color::White);
                window.draw(mainground1);
                window.draw(text1);
                window.display();
            }
            cout << "Albatross Game을 종료합니다.\n";
        }
        if (Keyboard::isKeyPressed(Keyboard::Num2) || Keyboard::isKeyPressed(Keyboard::Numpad2)) {
            cout << "Arrow Game에 접속합니다.\n";
            while (!Keyboard::isKeyPressed(Keyboard::Q)) {
                if (Keyboard::isKeyPressed(Keyboard::S)) {

                    time_t start = time(NULL); //점수
                    up.clear();
                    right.clear();
                    down.clear();
                    left.clear();
                    magickey = true;
                    hp2 = 3;
                    speedup = 0;
                    enemySpeed = 1;
                    cout << "Arrow Game을 시작합니다.\n";
                    while (!Keyboard::isKeyPressed(Keyboard::M)) {

                        // update
                        if (speedup >= 900) {
                            enemySpeed++;
                            speedup = 0;
                        }
                        else speedup++;

                        // obstacles (enemies)
                        for (size_t i = 0; i < up.size(); i++) {
                            up[i].move(0, enemySpeed);
                        }
                        for (size_t i = 0; i < right.size(); i++) {
                            right[i].move(-enemySpeed, 0);
                        }
                        for (size_t i = 0; i < down.size(); i++) {
                            down[i].move(0, -enemySpeed);
                        }
                        for (size_t i = 0; i < left.size(); i++) {
                            left[i].move(enemySpeed, 0);
                        }
                        if (enemySpawnTimer >= 14) {
                            int tmp = rand();
                            if (tmp % 4 == 0) {
                                up.push_back(ufoup);
                                up[up.size() - 1].setPosition((window.getSize().x / 2) - 50, 0);
                            }
                            else if (tmp % 4 == 1) {
                                right.push_back(uforight);
                                right[right.size() - 1].setPosition((window.getSize().x) - 50, (window.getSize().y / 2) - 50);
                            }
                            else if (tmp % 4 == 2) {
                                down.push_back(ufodown);
                                down[down.size() - 1].setPosition((window.getSize().x / 2) - 50, (window.getSize().y) - 50);
                            }
                            else if (tmp % 4 == 3) {
                                left.push_back(ufoleft);
                                left[left.size() - 1].setPosition(0, (window.getSize().y / 2) - 50);
                            }
                            enemySpawnTimer = 0;
                        }
                        else enemySpawnTimer++;

                        // collision
                        for (size_t i = 0; i < up.size(); i++) {
                            if (magician.getGlobalBounds().intersects(up[i].getGlobalBounds())) {
                                up.erase(up.begin() + i);
                                hp2--;
                                break;
                            }
                        }
                        for (size_t i = 0; i < right.size(); i++) {
                            if (magician.getGlobalBounds().intersects(right[i].getGlobalBounds())) {
                                right.erase(right.begin() + i);
                                hp2--;
                                break;
                            }
                        }
                        for (size_t i = 0; i < down.size(); i++) {
                            if (magician.getGlobalBounds().intersects(down[i].getGlobalBounds())) {
                                down.erase(down.begin() + i);
                                hp2--;
                                break;
                            }
                        }
                        for (size_t i = 0; i < left.size(); i++) {
                            if (magician.getGlobalBounds().intersects(left[i].getGlobalBounds())) {
                                left.erase(left.begin() + i);
                                hp2--;
                                break;
                            }
                        }

                        //break ufo
                        Event keyevent;
                        window.pollEvent(keyevent);
                        if (keyevent.type == Event::KeyReleased) magickey = true;
                        if (keyevent.type == Event::KeyPressed && magickey == true) {
                            if (Keyboard::isKeyPressed(Keyboard::Up))
                            {
                                if (up.size() == 0) hp2--;
                                else {
                                    effects.push_back({ effect, 0 });
                                    effects[effects.size() - 1].first.setPosition(up[0].getPosition().x - 30, up[0].getPosition().y - 30);
                                    up.erase(up.begin(), up.begin() + 1);
                                }
                                magickey = false;
                            }
                            if (Keyboard::isKeyPressed(Keyboard::Down))
                            {
                                if (down.size() == 0) hp2--;
                                else {
                                    effects.push_back({ effect, 0 });
                                    effects[effects.size() - 1].first.setPosition(down[0].getPosition().x - 30, down[0].getPosition().y - 30);
                                    down.erase(down.begin(), down.begin() + 1);
                                }
                                magickey = false;
                            }
                            if (Keyboard::isKeyPressed(Keyboard::Left))
                            {
                                if (left.size() == 0) hp2--;
                                else {
                                    effects.push_back({ effect, 0 });
                                    effects[effects.size() - 1].first.setPosition(left[0].getPosition().x - 30, left[0].getPosition().y - 30);
                                    left.erase(left.begin(), left.begin() + 1);
                                }
                                magickey = false;
                            }
                            if (Keyboard::isKeyPressed(Keyboard::Right))
                            {
                                if (right.size() == 0) hp2--;
                                else {
                                    effects.push_back({ effect, 0 });
                                    effects[effects.size() - 1].first.setPosition(right[0].getPosition().x - 30, right[0].getPosition().y - 30);
                                    right.erase(right.begin(), right.begin() + 1);
                                }
                                magickey = false;
                            }
                        }

                        //effect
                        for (int i = 0; i < effects.size(); i++) {
                            if (effects[i].second >= 10) effects.erase(effects.begin() + i);
                            else effects[i].second++;
                        }

                        // draw
                        window.clear(Color::Black);
                        window.draw(background2);
                        window.draw(magician);
                        for (size_t i = 0; i < up.size(); i++) {
                            window.draw(up[i]);
                        }
                        for (size_t i = 0; i < right.size(); i++) {
                            window.draw(right[i]);
                        }
                        for (size_t i = 0; i < down.size(); i++) {
                            window.draw(down[i]);
                        }
                        for (size_t i = 0; i < left.size(); i++) {
                            window.draw(left[i]);
                        }
                        for (size_t i = 0; i < effects.size(); i++) {
                            window.draw(effects[i].first);
                        }
                        if (hp2 > 0) {
                            if (hp2 == 3) {
                                window.draw(hp_s2[0]);
                                window.draw(hp_s2[1]);
                                window.draw(hp_s2[2]);
                            }
                            else if (hp2 == 2) {
                                window.draw(hp_s2[0]);
                                window.draw(hp_s2[1]);
                            }
                            else if (hp2 == 1) {
                                window.draw(hp_s2[0]);
                            }
                        }
                        else {
                            //점수
                            time_t end = time(NULL);
                            int x = (end - start);
                            if (x > stoi(s2)) s2 = to_string(x);
                            while (!Keyboard::isKeyPressed(Keyboard::M) && !Keyboard::isKeyPressed(Keyboard::R)) {
                                window.clear(Color::White);
                                window.draw(overground);
                                Text overtext2;
                                string overmsg2 = "Max Score : " + s2 + "\nScore : " + to_string(x);
                                textSetting(overtext2, font, 45, 400, 465, Color::White, Color::Black, overmsg2);
                                window.draw(overtext2);
                                window.display();
                            }
                            if (Keyboard::isKeyPressed(Keyboard::M)) {

                            }
                            else if (Keyboard::isKeyPressed(Keyboard::R)) {
                                start = time(NULL); //점수
                                hp2 = 3;
                                up.clear();
                                right.clear();
                                down.clear();
                                left.clear();
                                magickey = true;
                                speedup = 0;
                                enemySpeed = 1;
                                cout << "Arrow Game을 시작합니다.\n";
                            }
                        }

                        window.display();
                    }
                    cout << "Arrow Game 매인화면으로 갑니다.\n";
                }
                //Arrow Game main draw
                mainground2.setPosition(0, 0);
                window.clear(Color::White);
                window.draw(mainground2);
                window.draw(text2);
                window.display();
            }
            cout << "Arrow Game을 종료합니다.\n";
        }
        if (Keyboard::isKeyPressed(Keyboard::Num3) || Keyboard::isKeyPressed(Keyboard::Numpad3)) {
            cout << "Catching Alos Game에 접속합니다.\n";
            while (!Keyboard::isKeyPressed(Keyboard::Q)) {
                if (Keyboard::isKeyPressed(Keyboard::S)) {
                    //초기화
                    input_numbers = "";
                    x3 = 0, y3 = 0, n3 = 0;
                    xx3 = 0, yy3 = 0;
                    //com_numbers = "";
                    level = 1;
                    game_start = 0;
                    levelLoop = 0;
                    number_order = 0, delay_number_order = 1.5;  //interval for show each color
                    game_start = 0, delay_game_start = 2.0;      //wait for game start
                    ready = 0, delay_ready = 2.0;                //Show "Ready, Go" message for 2 seconds
                    level_string = "Level : " + to_string(level);
                    textSetting(text_level, font_level, 30, 10.f, 10.f,
                        Color::Black, Color::Black, level_string);
                    message_string = "Ready, Go!";
                    textSetting(text_message, font_message, 30, 10.f, 50,
                        Color::Black, Color::Black, "");
                    isgamestart = false;
                    idx3 = 0;        
                    //초기화
                    
                    //게임 시작
                    cout << "Catching Alos Game을 시작합니다.\n";
                    while (!Keyboard::isKeyPressed(Keyboard::M)) {

                        // game update
                        float time = clock3.getElapsedTime().asSeconds();
                        clock3.restart();
                        number_order += time;
                        game_start += time;
                        ready += time;

                        Event event3;

                        while (window.pollEvent(event3)) {
                            if (event3.type == Event::EventType::Closed)
                                window.close();
                        }

                        if (event3.type == Event::MouseButtonPressed)
                        {
                            if (event3.key.code == Mouse::Left)
                            {
                                if (isgamestart == true)
                                {
                                    Vector2i pos = Mouse::getPosition(window);
                                    y3 = (pos.x - KEYPAD_START_X) / KEYPAD_BTN_WIDTH;
                                    x3 = (pos.y - KEYPAD_START_Y) / KEYPAD_BTN_HEIGHT;
                                    n3 = color_grid[x3][y3];
                                    //cout << "[USER]Pressed:: x=" << y3 << " y = " << x3 << " n=" << n3 << endl;

                                    //Save input numbers
                                    if (input_numbers.length() < level)
                                        input_numbers += to_string(n3);

                                    //Pressed effect
                                    for (int i = 0; i < 10; i++) {// 반복해서 오래 보여줘야 더 그럴싸함
                                        if (n3 == 1) {
                                            sprite_on[2].setPosition(
                                                (float)((x3)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X + 140,
                                                (float)KEYPAD_START_Y + ((y3)*KEYPAD_BTN_HEIGHT) + 20);
                                        }
                                        else if (n3 == 2) {
                                            sprite_on[1].setPosition(
                                                (float)((x3)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X + 140,
                                                (float)KEYPAD_START_Y + ((y3)*KEYPAD_BTN_HEIGHT) + 20);
                                        }
                                        else {
                                            sprite_on[n3].setPosition(
                                                (float)((x3)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X + 140,
                                                (float)KEYPAD_START_Y + ((y3)*KEYPAD_BTN_HEIGHT) + 20);
                                        }
                                        window.draw(sprite_on[n3]);
                                        window.display();
                                    }
                                }
                            }
                            else  //Pressed Mouse right button
                                isgamestart = true;
                        }

                        if (input_numbers.length() == level)
                        {
                            if (com_numbers == input_numbers)
                            {
                                if (level > stoi(s3)) s3 = to_string(level);
                                input_numbers.clear();
                                level++;
                                delay_number_order -= 0.2f;
                                level_string = "Level : " + to_string(level) + " | Correct";
                                textSetting(text_level, font_level, 30, 10.f, 10.f,
                                    Color::Black, Color::Black, level_string);
                            }
                            else {
                                while (!Keyboard::isKeyPressed(Keyboard::M) && !Keyboard::isKeyPressed(Keyboard::R)) {
                                    window.clear(Color::White);
                                    window.draw(overground);
                                    Text overtext3;
                                    string overmsg3 = "Max Score : " + s3 + "\nScore : " + to_string(level - 1);
                                    textSetting(overtext3, font, 45, 400, 465, Color::White, Color::Black, overmsg3);
                                    window.draw(overtext3);
                                    window.display();
                                    input_numbers.clear();
                                }
                                if (Keyboard::isKeyPressed(Keyboard::M)) {
                                    generate_random_number();
                                    input_numbers = "";
                                    x3 = 0, y3 = 0, n3 = 0;
                                    xx3 = 0, yy3 = 0;

                                    number_order = 0, delay_number_order = 1.5;  //interval for show each color
                                    game_start = 0, delay_game_start = 2.0;      //wait for game start
                                    ready = 0, delay_ready = 2.0;                //Show "Ready, Go" message for 2 seconds

                                    level_string = "Level : " + to_string(level);
                                    message_string = "Ready, Go!";
                                    isgamestart = false;
                                    idx3 = 0;

                                    com_numbers = "";
                                    level = 1;

                                    time = clock3.getElapsedTime().asSeconds();
                                    clock3.restart();
                                    number_order += time;
                                    game_start += time;
                                    ready += time;
                                }
                                else if (Keyboard::isKeyPressed(Keyboard::R)) {
                                    generate_random_number();
                                    input_numbers = "";
                                    x3 = 0, y3 = 0, n3 = 0;
                                    xx3 = 0, yy3 = 0;

                                    number_order = 0, delay_number_order = 1.5;  //interval for show each color
                                    game_start = 0, delay_game_start = 2.0;      //wait for game start
                                    ready = 0, delay_ready = 2.0;                //Show "Ready, Go" message for 2 seconds

                                    isgamestart = false;
                                    idx3 = 0;

                                    com_numbers = "";
                                    level = 1;
                                    level_string = "Level : " + to_string(level);
                                    textSetting(text_level, font_level, 30, 10.f, 10.f,
                                        Color::Black, Color::Black, level_string);
                                    message_string = "Ready, Go!";
                                    textSetting(text_message, font_message, 30, 10.f, 50,
                                        Color::Black, Color::Black, "");
                                    time = clock3.getElapsedTime().asSeconds();
                                    clock3.restart();
                                    number_order += time;
                                    game_start += time;
                                    ready += time;
                                    cout << "Catching Alos Game Game을 시작합니다.\n";
                                }
                            }

                            generate_random_number();

                            game_start = 0;
                            levelLoop = 0;
                            clock3.restart();
                            number_order += time;
                        }


                        if (isgamestart == false)
                        {
                            window.draw(sprite_start_logo);

                            level_string = "Press Mouse Right button to start.";
                            textSetting(text_message, font_message, 30, 10.f, 50,
                                Color::Black, Color::Black, level_string);

                            game_start = 0;
                            number_order = 0;
                        }
                        else {
                            //draw color grid
                            for (int i = 0; i < 2; i++) {
                                for (int j = 0; j < 2; j++) {
                                    n3 = color_grid[i][j];
                                    sprite_off[n3].setPosition(
                                        (float)j * KEYPAD_BTN_WIDTH + KEYPAD_START_X + 140,
                                        (float)KEYPAD_START_Y + (i * KEYPAD_BTN_HEIGHT) + 20);
                                    window.draw(sprite_off[n3]);
                                }
                            }

                            //Remove "Ready, Go ! message after 2 seconds
                            if (ready > delay_ready) {
                                textSetting(text_message, font_message, 30, 10.f, 50,
                                    Color::Black, Color::Black, "");
                            }

                            //Game Start after 3.0 seconds
                            if (game_start > delay_game_start)
                            {
                                //Show the sprite_on image every 1 second each color
                                if (number_order > delay_number_order)
                                {
                                    if (levelLoop < level)
                                    {
                                        idx3 = (com_numbers.at(levelLoop)) - '0';
                                        //cout << "[ COM]Pressed idx = " << idx3 << endl;
                                        switch (idx3)
                                        {
                                        case 0:  xx3 = 0; yy3 = 0;  break;
                                        case 1:  xx3 = 1; yy3 = 0;  break;
                                        case 2:  xx3 = 0; yy3 = 1;  break;
                                        case 3:  xx3 = 1; yy3 = 1;  break;
                                        }

                                        //Press effect
                                        for (int i = 0; i < 15; i++)
                                        {
                                            sprite_on[idx3].setPosition(
                                                (float)((xx3)*KEYPAD_BTN_WIDTH) + KEYPAD_START_X + 140,
                                                (float)KEYPAD_START_Y + ((yy3)*KEYPAD_BTN_HEIGHT) + 20);
                                            window.draw(sprite_on[idx3]);
                                            window.display();
                                        }

                                        levelLoop++;
                                    }
                                    number_order = 0;
                                }
                            }
                        }

                        //game draw
                        window.clear(Color::White);
                        background3.setPosition(0, 0);
                        window.draw(background3);
                        window.draw(text_level);
                        window.draw(text_message);
                        window.display();
                    }
                    cout << "Catching Alos Game 매인화면으로 갑니다.\n";
                }
                //Game main draw
                mainground3.setPosition(0, 0);
                window.clear(Color::White);
                window.draw(mainground3);
                window.draw(text3);
                window.display();
            }
            cout << "Catching Alos Game을 종료합니다.\n";
        }
        if (Keyboard::isKeyPressed(Keyboard::Num4) || Keyboard::isKeyPressed(Keyboard::Numpad4)) {
            cout << "Tier Upgrade Game에 접속합니다.\n";
            string percentage;
            while (!Keyboard::isKeyPressed(Keyboard::Q)) {
                if (Keyboard::isKeyPressed(Keyboard::S)) {
                    description_string = "Bronze 5";
                    level4 = 0;
                    //게임 시작
                    cout << "Tier Upgrade Game을 시작합니다.\n";
                    while (!Keyboard::isKeyPressed(Keyboard::M)) {

                        // game update
                        key_bool = true;

                        // 티어 출력하기
                        percentage.clear();
                        if (level4 < 10) percentage = to_string(success[level4]) + " % / " + to_string(fail[level4]) + " %";
                        else percentage = to_string(success[level4]) + " % / " + to_string(fail[level4]) + " % / " + to_string(100 - success[level4] - fail[level4]) + " %";

                        textSetting(percen, font, 30, WIDTH / 2 - 80, HEIGHT / 3 * 2, Color::Black, Color::White, percentage);
                        textSetting(description, font, 40, WIDTH / 2 - 80, 50, Color::Black, Color::White, description_string);

                        Event keyEvent;
                        window.pollEvent(keyEvent);
                        if (keyEvent.type == Event::KeyReleased) key_bool = true;
                        if (keyEvent.type == Event::KeyPressed and key_bool) {
                            if (Keyboard::isKeyPressed(Keyboard::Y)) {
                                randint();
                                if (level4 == 30) {
                                    //축하하며 끝내기
                                    window.clear(Color::White);
                                    window.draw(goods);
                                    window.display();
                                }
                                else if (level4 < 10) { // Silver까지 강화
                                    if (num4 < success[level4]) { // 강화 성공
                                        level4++;
                                        if (level4 > high_level) high_level = level4;
                                        if (!(level4 % 5)) {
                                            description_string.clear();
                                            switch (level4) {
                                            case 5: description_string = "Silver 5";
                                                break;
                                            case 10: description_string = "Gold 5";
                                                break;
                                            }
                                        }
                                        else description_string[description_string.length() - 1]--;
                                    }
                                    else { // 강화 실패
                                        level4--;
                                        if (!((level4 + 1) % 5)) {
                                            description_string.clear();
                                            switch (level4 + 1) {
                                            case 0:level4 = 0;
                                                description_string = "Bronze 5";
                                                break;
                                            case 5:description_string = "Bronze 1";
                                                break;
                                            }
                                        }
                                        else description_string[description_string.length() - 1]++;
                                    }
                                    // 티어 & 확률 수정
                                    textSetting(description, font, 40, WIDTH / 2 - 80, 50, Color::Black, Color::White, description_string);
                                    textSetting(percen, font, 30, WIDTH / 2 - 80, HEIGHT / 3 * 2, Color::Black, Color::White, percentage);
                                }
                                else { // Gold 이상
                                    if (num4 < success[level4]) { // 강화 성공
                                        level4++;
                                        if (level4 > high_level) high_level = level4;
                                        if (!(level4 % 5)) {
                                            description_string.clear();
                                            switch (level4) {
                                            case 15: description_string = "Platinum 5";
                                                break;
                                            case 20: description_string = "Diamond 5";
                                                break;
                                            case 25:description_string = "Ruby 5";
                                                break;
                                            }
                                        }
                                        else description_string[description_string.length() - 1]--;
                                    }
                                    else if (num4 < 100 - fail[level4]) { // 강화 파괴
                                        level4 = 0;
                                        description_string.clear();
                                        description_string = "Bronze 5";
                                        //폭발 이펙트 넣기
                                        for (int i = 0; i < 10; i++) {
                                            window.draw(booms);
                                            window.display();
                                        }
                                    }
                                    else { // 강화 실패
                                        level4--;
                                        if (!((level4 + 1) % 5)) {
                                            description_string.clear();
                                            switch (level4 + 1) {
                                            case 15:description_string = "Gold 1";
                                                break;
                                            case 20:description_string = "Platinum 1";
                                                break;
                                            case 25:description_string = "Diamond 1";
                                                break;
                                            }
                                        }
                                        else description_string[description_string.length() - 1]++;
                                    }
                                    // 티어 수정
                                    textSetting(description, font, 40, WIDTH / 2 - 80, 50, Color::Black, Color::White, description_string);
                                }
                                key_bool = false;
                            }
                            else if (Keyboard::isKeyPressed(Keyboard::N)) { // N 눌렀을 경우
                                //점수
                                if (high_level+1 > stoi(s4)) s4 = to_string(high_level+1);
                                
                                while (!(Keyboard::isKeyPressed(Keyboard::R)) and !(Keyboard::isKeyPressed(Keyboard::M))) {
                                    description_string.clear();
                                    switch (high_level / 5) {
                                    case 0:description_string += "Bronze ";
                                        break;
                                    case 1:description_string += "Silver ";
                                        break;
                                    case 2:description_string += "Gold ";
                                        break;
                                    case 3:description_string += "Platinum ";
                                        break;
                                    case 4:description_string += "Diamond ";
                                        break;
                                    case 5:description_string += "Ruby ";
                                        break;
                                    }
                                    switch (high_level % 5) {
                                    case 0:description_string += "5";
                                        break;
                                    case 1:description_string += "4";
                                        break;
                                    case 2:description_string += "3";
                                        break;
                                    case 3:description_string += "2";
                                        break;
                                    case 4:description_string += "1";
                                        break;
                                    }
                                    textSetting(description, font, 100, WIDTH / 3, 30, Color::Black, Color::White, description_string);
                                    window.clear(Color::White);
                                    background4.setPosition(0, 0);
                                    window.draw(background4);
                                    window.draw(description);
                                    window.draw(tier[high_level]);
                                    window.display();

                                    if (Keyboard::isKeyPressed(Keyboard::M)) {

                                    }
                                    else if (Keyboard::isKeyPressed(Keyboard::R)) {
                                        //재시작
                                        description_string.clear();
                                        description_string = "Bronze 5";
                                        textSetting(description, font, 40, WIDTH / 2 - 80, 50, Color::Black, Color::White, description_string);
                                        level4 = 0;
                                        cout << "Tier Upgrade를 시작합니다.\n";
                                    }
                                }
                            }
                            key_bool = false;
                            //game draw
                            percentage.clear();
                            if (level4 < 10) {
                                percentage = to_string(success[level4]) + " % / " + to_string(fail[level4]) + " %";
                                textSetting(percen, font, 60, WIDTH / 2 - 180, HEIGHT / 3 * 2 - 300, Color::Black, Color::White, percentage);
                            }
                            else {
                                percentage = to_string(success[level4]) + " % / " + to_string(fail[level4]) + " % / " + to_string(100 - success[level4] - fail[level4]) + " %";
                                textSetting(percen, font, 60, WIDTH / 3 - 80, HEIGHT / 3 * 2 - 300, Color::Black, Color::White, percentage);
                            }

                            window.clear(Color::White);
                            background4.setPosition(0, 0);
                            window.draw(background4);
                            window.draw(tier[level4]);
                            window.draw(description);
                            window.draw(percen);
                            window.display();
                        }
                    }
                    cout << "Tier Upgrade Game 매인화면으로 갑니다.\n";
                }
                //Game main draw
                msg4 = "Max\nScore\n: " + s4;
                textSetting(text4, font, 60, 55, 70, Color::Black, Color::White, msg4);
                mainground4.setPosition(0, 0);
                window.clear(Color::White);
                window.draw(mainground4);
                window.draw(text4);
                window.display();
            }
            cout << "Tier Upgrade Game을 종료합니다.\n";
        }

        //minigame main draw
        window.clear(Color::White);
        minigameground.setPosition(0, 0);
        window.draw(minigameground);
        window.display();
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            cout << "미니게임천국을 종료합니다.\n";
            window.close();
        }
    }
    //점수 기록
    ofstream upscore("score.txt");
    upscore << s1 << "\n" << s2 << "\n" << s3 << "\n" << s4 << "\n";
    upscore.close();
    return 0;
}