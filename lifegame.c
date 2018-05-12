#include<stdio.h>
#include<stdbool.h>

//�Ֆʂ̏���������̔ՖʂɃR�s�[
void copy_board(const int w, const int h, bool current_board[w][h], bool tmp_board[w][h]){
	int i, j;
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			tmp_board[j][i] = current_board[j][i];
		}
	}
}

//�Ֆʂ�W���o�͂ɕ\��
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
	
	//�Ֆʂ̃Z�������ׂĎ���ł����Ԃŏ�����
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			current_board[j][i] = false;
		}
	}
	
	//input�̏������Ƃɑ�1����Ő����Ă���Z����ݒ�
	for(i = 0; i < input_length; i++){
		current_board[input[i] / 10][input[i] % 10] = true;
	}
	
	print_board(w, h, current_board);
}


int main()
{
	const int w = 10;	//�Ֆʂ̉���
	const int h = 10;	//�Ֆʂ̏c��
	int input[] = {11, 22, 3, 13, 23};	//��1����Ő������Ă���Z���̍��W(x,y)��10x+y�̌`�ŕ\��������
	int input_length = 5;	//input[]�̗v�f��
	
	lifegame(w, h, input, input_length);
	
	return 0;

}