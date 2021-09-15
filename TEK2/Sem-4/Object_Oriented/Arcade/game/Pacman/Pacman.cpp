/*
** EPITECH PROJECT, 2020
** B-OOP-400-MPL-4-1-arcade-corentin.petrau
** File description:
** pacman.cpp
*/

#include "Pacman.hpp"

arcade::Pacman::Pacman()
{
    this->score = 0;
    this->name = "Pacman";
    this->direction = 1;
    this->posY = 0;
    this->posX = 0;
    this->over = false;
}

void arcade::Pacman::init(void)
{
    std::fstream myfile;
    std::string line;

    myfile.open("./game/Pacman/mapPacman.txt", std::ios::in);
    if (myfile)
        for (long unsigned int i = 0; getline(myfile, line); i++)
            this->map.push_back(line);
    myfile.close();
    for (size_t i = 0; map.size() > i; i++) {
        for (size_t j = 0; map[i].size() > j; j++) {
            if (map[i][j] == 'P') {
                this->posX = j;
                this->posY = i;
            }
        }
    }
}

bool arcade::Pacman::is_over()
{
    return this->over;
}

void arcade::Pacman::stop(void)
{
    this->over = true;
}

std::vector<arcade::GameObject> &arcade::Pacman::update(std::vector<arcade::Input::Key> input)
{
    GameObject wall = Sprite("./game/Pacman/assets/pacman_wall.png");
    GameObject door = Sprite("./game/Pacman/assets/pacman_door.png");
    GameObject fruit = Sprite("./game/Pacman/assets/pacman_fruit.png");
    GameObject Pacman = Sprite("./game/Pacman/assets/pacman.png");
    GameObject line = Sprite("./game/Pacman/assets/pacman_line.png");
    GameObject end = Sprite("./game/Pacman/assets/pacman_end.png");
    GameObject gum = Sprite("./game/Pacman/assets/pacman_gum.png");
    GameObject ghost = Sprite("./game/Pacman/assets/pacman_ghost.png");
    GameObject space = Sprite("./game/Pacman/assets/pacman_space.png");

    if (input.size() > 0 && input[0] == arcade::Input::Z)
        this->direction = 1;
    if (input.size() > 0 && input[0] == arcade::Input::S)
        this->direction = 2;
    if (input.size() > 0 && input[0] == arcade::Input::Q)
        this->direction = 3;
    if (input.size() > 0 && input[0] == arcade::Input::D)
        this->direction = 4;

    if (this->direction == 1)
        this->map = this->go_up();
    else if (this->direction == 2)
        this->map = this->go_down();
    else if (this->direction == 3)
        this->map = this->go_left();
    else if (this->direction == 4)
        this->map = this->go_right();

    for (size_t i = 0; this->map.size() > i; i++) {
        for (size_t j = 0; this->map[i].size() > j; j++) {
            if (this->map[i][j] == 'G') {
                this->GposX = j;
                this->GposY = i;
                this->map = this->ia_move();
            }
        }
    }
    if (this->posX == 68) {
        this->map[posY][posX] = ' ';
        this->posX = 1;
    }
    if (this->posX == 0) {
        this->map[posY][posX] = ' ';
        this->posX = 67;
    }
    this->map[posY][posX] = 'P';
    this->object.clear();
    for (size_t i = 0; this->map.size() > i; i++) {
        for (size_t j = 0; this->map[i].size() > j; j++) {
            if (this->map[i][j] == '#') {
                wall.position = Vector2(i, j);
                this->object.push_back(wall);
            } else if (this->map[i][j] == 'G') {
                ghost.position = Vector2(i, j);
                this->object.push_back(ghost);
            } else if (this->map[i][j] == 'o') {
                gum.position = Vector2(i, j);
                this->object.push_back(gum);
            } else if (this->map[i][j] == 'P') {
                Pacman.position = Vector2(i, j);
                this->object.push_back(Pacman);
            } else if (this->map[i][j] == '.') {
                fruit.position = Vector2(i, j);
                this->object.push_back(fruit);
            } else if (this->map[i][j] == '*') {
                door.position = Vector2(i, j);
                this->object.push_back(door);
            } else if (this->map[i][j] == ' ') {
                space.position = Vector2(i, j);
                this->object.push_back(space);
            }
        }
    }
    return this->object;
}

const std::string &arcade::Pacman::getName(void)
{
    return this->name;
}

int arcade::Pacman::get_score(void)
{
    return this->score;
}

std::vector<std::string> arcade::Pacman::iago_up(void)
{
    if (this->map[this->GposY-1][this->GposX] == '#' || this->map[this->GposY-1][this->GposX] == 'G')
        return this->map;
    this->map[this->GposY][this->GposX] = '.';
    this->GposY -= 1;
    this->map[this->GposY][this->GposX] = 'G';
    return this->map;
}

std::vector<std::string> arcade::Pacman::iago_down(void)
{
    if (this->map[this->GposY+1][this->GposX] == '#' || this->map[this->GposY+1][this->GposX] == 'G')
        return this->map;
    this->map[this->GposY][this->GposX] = '.';
    this->GposY += 1;
    this->map[this->GposY][this->GposX] = 'G';
    return this->map;
}

std::vector<std::string> arcade::Pacman::iago_left(void)
{
    if (this->map[this->GposY][this->GposX-1] == '#' || this->map[this->GposY][this->GposX-1] == 'G')
        return this->map;
    this->map[this->GposY][this->GposX] = '.';
    this->GposX -= 1;
    this->map[this->GposY][this->GposX] = 'G';
    return this->map;
}

std::vector<std::string> arcade::Pacman::iago_right(void)
{
    if (this->map[this->GposY][this->GposX+1] == '#' || this->map[this->GposY][this->GposX+1] == 'G')
        return this->map;
    this->map[this->GposY][this->GposX] = '.';
    this->GposX += 1;
    this->map[this->GposY][this->GposX] = 'G';
    return this->map;
}

std::vector<std::string> arcade::Pacman::ia_move(void)
{
    int i = rand() % 100;
    if (i > 0 && i < 25)
        this->map = this->iago_up();
    if (i > 25 && i < 50)
        this->map = this->iago_down();
    if (i > 50 && i < 75)
        this->map = this->iago_left();
    if (i > 75 && i < 100)
        this->map = this->iago_right();
    return this->map;
}

std::vector<std::string> arcade::Pacman::go_up(void)
{
    if (this->map[this->posY-1][this->posX] == '#')
        return this->map;
    this->map[this->posY][this->posX] = ' ';
    if (this->map[this->posY-1][this->posX] == '.')
        this->score += 1;
    if (this->map[this->posY-1][this->posX] == 'G')
        stop();
    this->posY -= 1;
    this->map[this->posY][this->posX] = 'P';
    return this->map;
}

 std::vector<std::string> arcade::Pacman::go_down(void)
{
    if (this->map[this->posY+1][this->posX] == '#' || this->map[this->posY+1][this->posX] == '*')
        return this->map;
    this->map[this->posY][this->posX] = ' ';
    if (this->map[this->posY+1][this->posX] == '.')
        this->score += 1;
    if (this->map[this->posY+1][this->posX] == 'G')
        stop();
    this->posY += 1;
    this->map[this->posY][this->posX] = 'P';
    return this->map;
}

std::vector<std::string> arcade::Pacman::go_left(void)
{
    if (this->map[this->posY][this->posX-1] == '#')
        return this->map;
    this->map[this->posY][this->posX] = ' ';
    if (this->map[this->posY][this->posX-1] == '.')
        this->score += 1;
    if (this->map[this->posY][this->posX-1] == 'G')
        stop();
    this->posX -= 1;
    this->map[this->posY][this->posX] = 'P';
    return this->map;
}

std::vector<std::string> arcade::Pacman::go_right(void)
{
    if (this->map[this->posY][this->posX+1] == '#')
        return this->map;
    this->map[this->posY][this->posX] = ' ';
    if (this->map[this->posY][this->posX+1] == '.')
        this->score += 1;
    if (this->map[this->posY][this->posX+1] == 'G')
        stop();
    this->posX += 1;
    this->map[this->posY][this->posX] = 'P';
    return this->map;
}

extern "C" {
    arcade::IGameModule *entryPoint(void) {
        return(new arcade::Pacman());
    }
}
