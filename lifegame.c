#include<stdio.h>
#include<stdbool.h>

//board_a�̏���board_b�ɃR�s�[
void copy_board(int w, int h, bool board_a[w][h], bool board_b[w][h]){
	int i, j;
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			board_b[j][i] = board_a[j][i];
		}
	}
}

//�Ֆʂ�W���o�͂ɕ\��
void print_board(int w, int h, bool current_board[w][h]){
	int i, j;
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(current_board[j][i]){
				printf("* ");
			}else{
				printf("- ");
			}
			if(j == (w - 1)) printf("\n");
		}
	}
}

//�Z���̎���8�}�X��T�����C�����Ă���Z���̐���Ԃ�
int search(int w, int h, bool current_board[w][h],int  x,int  y){
	int num_of_alive = 0;
	int i, j;
	
	for(i = (y - 1); i <= (y + 1); i++){
		for(j = (x - 1); j <= (x + 1); j++){
			if(i == y && j == x) continue;	//���S�̃Z���͖���
			if(j >= 0 && i >= 0 && j < w && i < h)	//�֖ʂ̊O������
				if(current_board[j][i]) ++num_of_alive;
		}
	}
	
	return num_of_alive;
}

//�Ֆʂ�1����i�߂�
void next(int w, int h, bool current_board[w][h], bool shadow_board[w][h]){
	int i, j;
	
	copy_board(w, h, current_board, shadow_board);
	
	
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(current_board[j][i]){	//�����Ă���Z���̎��͂ɁC2�܂���3�̐����Ă���Z��������΂��̃Z���͐���
				if(search(w, h, current_board, j, i) <= 1 || search(w, h, current_board, j, i) >= 4) shadow_board[j][i] = false;
			}else{	//����ł���Z���̎��͂ɁC3�̐����Ă���Z��������ΐ����Ă���Z�����a��
				if(search(w, h, current_board, j, i) == 3) shadow_board[j][i] = true;
			}
		}
	}
	
	copy_board(w, h, shadow_board, current_board);

}

void lifegame(int w,int h, int *input, int input_length){
	bool current_board[w][h];
	bool shadow_board[w][h];
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
	
	//�Ֆʂ�12����i�߂�
	for(i = 0; i < 12; i++){
		next(w, h, current_board, shadow_board);
	}
	
	//�Ֆʂ�\��
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