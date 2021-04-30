/*
** EPITECH PROJECT, 2019
** FIR TREE
** File description:
** display a fir tree, based on its given size
*/
void tree(int size)
{
  int lines = 0;
  int star = 1;
  int base = 7;
  int add = 6;
  int count = 1;
  int space;

  if(size <= 0){
      return(0);
  }

   while(count < size)
    {
        if( count%2 == 0){
            base = base + (add + 2);
            add = add + 2;
            count++;
        }else{
            base = base + add;
            count++;
        }
    }
    disp_star(space, lines, base, star, size);
}
int disp_star(int space, int lines, int base, int star, int size)
{
    int temp;
    int temp2 = star;
    int count = 4;
    int count2 = 1;

    space =0.5*base;
    temp = space;
    while(star <= base) {
        while(count2 <= size){
            while(count2 + lines <= count){
                while(space > 0) {
                my_putchar(' ');
                space--;
                }
                while(star > 0) {
                my_putchar('*');
                star--;
                }
                my_putchar('\n');
                lines++;
                star = temp2;
                star +=2;
                temp2 = star;
                space = temp - 1;
                temp--;
            }
            count+=2;
            lines = 0;
            count2++;
            if (count2 > 1 && lines == 0){
                    space+=2;
                    star-=4;
                    temp = space;
                    temp2 = star;
            }
        }
        return(0);
    }
}
int tree_trunk(int size, int base, int space)
{
    int count_truck = 1;
    int add_truck = 6;
    int trunk = 1;

    space = 0.5*base;
    while(count_truck < size)
    {
        if( count_truck%2 == 0){
            base = base + (add_truck + 2);
            add_truck = add_truck + 2;
            count_truck++;
        }else{
            base = base + add_truck;
            count_truck++;
        }
        while(space < base) {
            my_putchar(' ');
            space--;
        }
        while(trunk > 0) {
                my_putchar('|');
                trunk--;
        }
    }
    return(0);
}