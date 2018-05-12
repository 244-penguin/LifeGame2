#include<stdio.h>
#include<stdbool.h>

//盤面の情報をもう一つの盤面にコピー
void copy_board(const int w, const int h, bool current_board[w][h], bool tmp_board[w][h]){
	int i, j;
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			tmp_board[j][i] = current_board[j][i];
		}
	}
}

//盤面を標準出力に表示
void print_board(const int w, const int h, bool current_board[w][h]){
	int i, j;
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(current_board[j][i]){
				printf("*");
			}else{
				printf("-");
			}
			if(j == (w - 1)) printf("\n");
		}
	}
}

void lifegame(const int w,const int h, int *input, int input_length){
	bool current_board[w][h];
	bool tmp_baord[w][h];
	int i,j;
	
	//盤面のセルをすべて死んでいる状態で初期化
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			current_board[j][i] = false;
		}
	}
	
	//inputの情報をもとに第1世代で生きているセルを設定
	for(i = 0; i < input_length; i++){
		current_board[input[i] / 10][input[i] % 10] = true;
	}
	
	print_board(w, h, current_board);
}


int main()
{
	const int w = 10;	//盤面の横幅
	const int h = 10;	//盤面の縦幅
	int input[] = {11, 22, 3, 13, 23};	//第1世代で生存しているセルの座標(x,y)を10x+yの形で表したもの
	int input_length = 5;	//input[]の要素数
	
	lifegame(w, h, input, input_length);
	
	return 0;

}