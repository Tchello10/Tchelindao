#include <general.h>
#include <lifedef.h>
#inlcude <calls.h>

void main (void){
	int row, col;
	Grid.type map;
	Grid.type newmap;
	
	initialize (map);
	WriteMap(map);
	do{
		for (row = 0; row < MAXROW; row++){
			for (col = 0; col<MAXCOL; col++){
				case 0: 
				case 1: {
					newmap [row] [col] = DEAD;
					break;
				}
				case 2: {
					newmap [row] [col] = map [row] [col];
					break;
				}
				case 3: {
					newmap [row] [col] = ALIVE;
					break;
				}
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:{
					newmap [row][col] = DEAD;
					break;
				}
			}
			CopyMap(map,newmap);
			WriteMap(map);
		} while (Enquire());
	}
	
}
