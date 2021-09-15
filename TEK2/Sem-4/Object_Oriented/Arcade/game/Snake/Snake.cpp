/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** snake.cpp
*/

#include "Snake.hpp"
#include "GameObject.hpp"

arcade::Snake::Snake()
{
    this->score = 0;
    this->name = "Snake";
    this->direction = 1;
    this->posY = 0;
    this->posX = 0;
    this->over = false;
}

void arcade::Snake::init(void)
{
    std::fstream myfile;
    std::string line;

    myfile.open("./game/Snake/mapSnake.txt", std::ios::in);
    if (myfile)
        for (long unsigned int i = 0; getline(myfile, line); i++)
            this->map.push_back(line);
    myfile.close();
    for (size_t i = 0; map.size() > i; i++) {
        for (size_t j = 0; map[i].size() > j; j++) {
            if (map[i][j] == 'S') {
                this->posX = j;
                this->posY = i;
            }
            if (map[i][j] == 'x') {
                this->posFX = j;
                this->posFY = i;
            }
        }
    }
}

bool arcade::Snake::is_over()
{
    return this->over;
}

void arcade::Snake::stop(void)
{
    this->over = true;
}

std::vector<arcade::GameObject> &arcade::Snake::update(std::vector<arcade::Input::Key> input)
{
    GameObject wall = Sprite("./game/Snake/assets/nibbler_wall.png");
    GameObject space = Sprite("./game/Snake/assets/nibbler_space.png");
    GameObject fruit = Sprite("./game/Snake/assets/nibbler_fruit.png");
    GameObject snake = Sprite("./game/Snake/assets/nibbler.png");
    GameObject tail = Sprite("./game/Snake/assets/nibbler_tail.png");
    GameObject body = Sprite("./game/Snake/assets/nibbler_body.png");
    srand((unsigned int)time(0));
    if (input.size() > 0 && input[0] == arcade::Input::Z)
        this->direction = 1;
    if (input.size() > 0 && input[0] == arcade::Input::S)
        this->direction = 2;
    if (input.size() > 0 && input[0] == arcade::Input::Q)
        this->direction = 3;
    if (input.size() > 0 && input[0] == arcade::Input::D)
        this->direction = 4;

    if (this->direction == 1) {
        if (this->map[posY-1][posX] == '+' || this->map[posY-1][posX] == '/')
            stop();
        this->map = this->go_up();
    } else if (this->direction == 2) {
        if (this->map[posY+1][posX] == '+' || this->map[posY+1][posX] == '/')
            stop();
        this->map = this->go_down();
    } else if (this->direction == 3) {
        if (this->map[posY][posX-1] == '+' || this->map[posY][posX-1] == '/')
            stop();
        this->map = this->go_left();
    } else if (this->direction == 4) {
        if (this->map[posY][posX+1] == '+' || this->map[posY][posX+1] == '/')
            stop();
        this->map = this->go_right();
    }
    if (this->posY == this->posFY && this->posFX == this->posX) {
        this->posFY = rand()%39;
        this->posFX = rand()%65;
        this->score += 10;
        while (this->map[this->posFY][this->posFX] == '#' || this->map[this->posFY][this->posFX] == 'S') {
            this->posFY = rand()%39;
            this->posFX = rand()%65;
        }
    }
    this->map[posFY][posFX] = 'x';
    move_body_tail();
    this->object.clear();
    for (size_t i = 0; this->map.size() > i; i++) {
        for (size_t j = 0; this->map[i].size() > j; j++) {
            if (this->map[i][j] == '#') {
                wall.position = Vector2(i, j);
                this->object.push_back(wall);
            } else if (this->map[i][j] == ' ') {
                space.position = Vector2(i, j);
                this->object.push_back(space);
            } else if (this->map[i][j] == 'x') {
                fruit.position = Vector2(i, j);
                this->object.push_back(fruit);
            } else if (this->map[i][j] == 'S') {
                snake.position = Vector2(i, j);
                this->object.push_back(snake);
            } else if (this->map[i][j] == '+') {
                body.position = Vector2(i, j);
                this->object.push_back(body);
            } else if (this->map[i][j] == '/') {
                tail.position = Vector2(i, j);
                this->object.push_back(tail);
            }
        }
    }
    return this->object;
}

const std::string &arcade::Snake::getName(void)
{
    return this->name;
}

int arcade::Snake::get_score(void)
{
    return this->score;
}

std::vector<std::string> arcade::Snake::go_up(void)
{
    if (this->map[this->posY-1][this->posX] == '#' || this->map[this->posY-1][this->posX] == '+')
        stop();
    this->map[this->posY][this->posX] = ' ';
    this->map[this->posY-1][this->posX] = 'S';
    this->posY -= 1;
    return this->map;
}

 std::vector<std::string> arcade::Snake::go_down(void)
{
    if (this->map[this->posY+1][this->posX] == '#' || this->map[this->posY+1][this->posX] == '+')
        stop();
    this->map[this->posY][this->posX] = ' ';
    this->map[this->posY+1][this->posX] = 'S';
    this->posY += 1;
    return this->map;
}

std::vector<std::string> arcade::Snake::go_left(void)
{
    if (this->map[this->posY][this->posX-1] == '#' || this->map[this->posY][this->posX-1] == '+')
        stop();
    this->map[this->posY][this->posX] = ' ';
    this->map[this->posY][this->posX-1] = 'S';
    this->posX -= 1;
    return this->map;
}

std::vector<std::string> arcade::Snake::go_right(void)
{
    if (this->map[this->posY][this->posX+1] == '#' || this->map[this->posY][this->posX+1] == '+')
        stop();
    this->map[this->posY][this->posX] = ' ';
    this->map[this->posY][this->posX+1] = 'S';
    this->posX += 1;
    return this->map;
}

void arcade::Snake::move_body_tail(void)
{
    for (size_t i = 0; map.size() > i; i++) {
        for (size_t j = 0; map[i].size() > j; j++) {
            if (map[i][j] == '+') {
                if (this->direction == 1 && this->map[i-1][j] != '+' && this->map[i-1][j] != 'S') {
                    this->map[i-1][j] = '+';
                    this->map[i][j] = ' ';
                } else if (this->direction == 2 && this->map[i+1][j] != '+' && this->map[i+1][j] != 'S') {
                    this->map[i+1][j] = '+';
                    this->map[i][j] = ' ';
                } else if (this->direction == 3 && this->map[i][j-1] != '+' && this->map[i][j-1] != 'S') {
                    this->map[i][j-1] = '+';
                    this->map[i][j] = ' ';
                } else if (this->direction == 4 && this->map[i][j+1] != '+' && this->map[i][j+1] != 'S') {
                    this->map[i][j+1] = '+';
                    this->map[i][j] = ' ';
                }
            } else if (map[i][j] == '/') {
                if (this->direction == 1 && this->map[i-1][j] != '+') {
                    this->map[i-1][j] = '/';
                    this->map[i][j] = ' ';
                } else if (this->direction == 2 && this->map[i+1][j] != '+') {
                    this->map[i+1][j] = '/';
                    this->map[i][j] = ' ';
                } else if (this->direction == 3 && this->map[i][j-1] != '+') {
                    this->map[i][j-1] = '/';
                    this->map[i][j] = ' ';
                } else if (this->direction == 4 && this->map[i][j+1] != '+') {
                    this->map[i][j+1] = '/';
                    this->map[i][j] = ' ';
                }
            }
        }
    }
}

extern "C" {
    arcade::IGameModule *entryPoint(void) {
        return(new arcade::Snake());
    }
}