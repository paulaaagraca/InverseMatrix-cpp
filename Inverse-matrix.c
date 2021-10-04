#include <stdio.h>

//----------------------------------------------------------
//read matrix : cin>> in c++ , scanf() in c
int cin(float a[100][100]){
	int i,j,n;
	printf("\n Enter Length Of Matrix N*N : ");
	scanf("%d",&n);
	printf("\n--------------------------\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			printf(" Matrix[%d][%d] : ",i+1,j+1);
			scanf("%f",&a[i][j]);
		}
	printf("\n----------------------------------------------------\n");
return n;
}

//-----------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void cout(float a[100][100],int n,int show){
	int i,j;
	if(show == 1)
		for(i=0;i < n;i++){
			for(j=0;j < n;j++)
				printf(" %.2f \t",a[i][j]);
			printf("\n");
		}
	else if(show == 2){
		printf("\n\n The Inverse Of Matrix Is : \n\n");
		for (i=0;i<n;i++){
			for (j=0;j<n;j++)
				printf(" %.4f \t",a[i][j]);
			printf("\n");
		}
	}
}

// calculate minor of matrix OR build new matrix : k-had = minor
void minor(int row, int col, float b[row][col],float a[row][col],int i,int n){
   int j,l,h=0,k=0;
   for(l=1;l<n;l++)
      for( j=0;j<n;j++){
         if(j == i)
            continue;
         b[h][k] = a[l][j];
         k++;
         if(k == (n-1)){
            h++;
            k=0;
         }
      }
}// end minor function

//---------------------------------------------------
// calculate determinant of matrix
float det(int row, int col, float a[row][col], int n){
   int i;
   float b[row][col],sum=0;
   if (n == 1)
      return a[0][0];
   else if(n == 2)
      return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
   else
      for(i=0;i<n;i++){
         minor(row,col,b,a,i,n);   // read function
         sum = (float) (sum+a[0][i]*pow(-1,i)*det(row,col,b,(n-1))); 
      }
   return sum;
}// end det function

//---------------------------------------------------
// calculate transpose of matrix
void transpose(int row, int col, float c[row][col], float d[row][col], float n, float det){
   int i,j;
   float b[row][col];
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
         b[i][j] = c[j][i];
   for (i=0;i<n;i++)
      for (j=0;j<n;j++)
         d[i][j] = b[i][j]/det;
}// end transpose function

//---------------------------------------------------
// calculate cofactor of matrix
void cofactor(int row, int col, float a[row][col], float d[row][col], float n, float determinant){
   float b[row][col],c[row][col];
   int l,h,m,k,i,j;
   for (h=0;h<n;h++)
      for (l=0;l<n;l++){
         m=0;
         k=0;
         for (i=0;i<n;i++)
            for (j=0;j<n;j++)
               if (i != h && j != l){
                  b[m][k]=a[i][j];
                  if (k<(n-2))
                     k++;
                  else{
                     k=0;
                     m++;
                  }
               }
         c[h][l] = pow(-1,(h+l))*det(row,col,b,(n-1));  // c = cofactor Matrix
      }
   transpose(row,col,c,d,n,determinant);  // read function
}// end cofactor function

//---------------------------------------------------
// calculate inverse of matrix
void inverse(int row, int col, float a[row][col],float d[row][col],int n,float det){
   if(det == 0)
      printf("\nMatrix is singular / non invertible\n");
   else if(n == 1)
      d[0][0] = 1;
   else
      cofactor(row,col,a,d,n,det); // read function
}// end inverse function

//---------------------------------------------------
// show matrix : cout<< in c++ , printf() in c
void cout(int row, int col, float a[row][col],int n,int show){
   int i,j;
   if(show == 1)
      for(i=0;i < n;i++){
         for(j=0;j < n;j++)
            printf(" %.2f \t",a[i][j]);
         printf("\n");
      }
   else if(show == 2){
      printf("\n\n The Inverse Of Matrix Is : \n\n");
      for (i=0;i<n;i++){
         for (j=0;j<n;j++)
            printf(" %.4f \t",a[i][j]);
         printf("\n");
      }
   }
}
