#include "Start.h"

void Start::printStart() {
	system("mode con:cols=170 lines=43");
	Menu menu = Menu();

	menu.MovePosition(1,1);
	cout << "                          ,;**:.                            ";
	menu.MovePosition(1, 2);
	cout << "                       ~*-.,    ~*-                      ";
	menu.MovePosition(1, 3);
	cout << "                     .!,;~-~;;-   ,*.                       ";
	menu.MovePosition(1, 4);
	cout << "                    -; .*,          ;:                      ";
	menu.MovePosition(1, 5);
	cout << "          .--:;!;;~~: ,;             -:                     ";
	menu.MovePosition(1, 6);
	cout << "        !!.                           -;*=!:!*!;            ";
	menu.MovePosition(1, 7);
	cout << "      !- :~,:!.                                 ~:          ";
	menu.MovePosition(1, 8);
	cout << "    .! ;,~;                                       * ;,      ";
	menu.MovePosition(1, 9);
	cout << "    :  .:                                        -~! -.     ";
	menu.MovePosition(1, 10);
	cout << "   * * :                                         ~- ; !     ";
	menu.MovePosition(1, 11);
	cout << "  .~; !                                           -!: . ,   ";
	menu.MovePosition(1, 12);
	cout << "  ; !,                                            !! - ,~   ";
	menu.MovePosition(1, 13);
	cout << "  ! ,!                                            !: : ,,   ";
	menu.MovePosition(1, 14);
	cout << "  !  *                                            ;! ;,     ";
	menu.MovePosition(1, 15);
	cout << "  !  !                                             ! .      ";
	menu.MovePosition(1, 16);
	cout << "  ;                                                ,:       ";
	menu.MovePosition(1, 17);
	cout << "  :                                               * ~!-     ";
	menu.MovePosition(1, 18);
	cout << "   :                                                  ,;    ";
	menu.MovePosition(1, 19);
	cout << "   !                                                    ~   ";

	menu.MovePosition(1, 20);
	cout << "   :                                                  ,;    ";
	menu.MovePosition(1, 21);
	cout << "   !                                                    ~   ";




}





int main() {
	system("cls");
	Start start = Start();
	start.printStart();

	/*Main main = Main();
	main.printMain();*/
	return 0;
}
