void print_list(int *new_list, int count) {
   for (int i = 0; i < count; i++) {
     printf("%d", new_list[i]);
     if (i != count-1) {
       printf(", ");
     } else {
       printf("\n");
     }
   }
}
