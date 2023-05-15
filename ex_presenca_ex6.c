#include <stdio.h>

void tower_of_hanoi(int disks, char source, char auxiliary, char destination)
{
    if (disks == 1)
    {
        printf("(%c, %c)\n", source, destination);
        return;
    }
    tower_of_hanoi(disks - 1, source, destination, auxiliary);
    printf("(%c, %c)\n", source, destination);
    tower_of_hanoi(disks - 1, auxiliary, source, destination);
}

int main()
{
    int disks;
    scanf("%d", &disks);
    tower_of_hanoi(disks, 'O', 'A', 'D');
    return 0;
}
