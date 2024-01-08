#include <stdio.h>
#

const int TOTAL_REGISTROS = 9;
const int MAX_LINE_BUFFER = 25;


typedef struct 
{ 
    char[25] nombre;
    int codigo;
    int costo;
    int min;
    int act;
} TRegistro;

typedef struct 
{ 
    int codigo;
    int RRN;
} Campo;

void main(){
  const Campo[TOTAL_REGISTROS] Indice; 
  //1. Escribe archivo Registros.txt
  //2. Crear archivo binario DATOS.dat en modo escritura
  FILE* datos = fopen("DATOS.dat", "wb");
  fclose(datos);

  struct TRegsitro reg;
  int cnt = 0;
  FILE* regs = fopen("Registros.txt", "r");
  while(cnt < TOTAL_REGISTROS){
    &reg = leer_registro();
    serializar_registro(&reg);
    actualizar_indice(&reg, cnt);  
    cnt++;
  }
  fclose(regs);
  ordernar_indice(Indice, TOTAL_REGISTROS);

  // Usuario
  FILE* datos = fopen("DATOS.dat", "r");
  char option = '';
  char[10] codigo;
  while(option != 'n'){
    printf("Que numero quieres buscar?\n")
    scanf("%s", &codigo);
    int buscado = buscar_codigo_en_indice(codigo);
    if(buscado != -1) {
      struct TRegistro reg;
      int lugar = Indice[buscado].RRN;
      fseek(datos, lugar*sizeof(struct TRegistro), SEEK_SET);
      fread(&reg, sizeof(struct TRegistro), 1, datos);
      imprimir_registro(&reg);
    } else {
      printf("NO EXISTE");
    }
    printf("¿Quieres seguir buscando?\n");
    printf("Si (s)      No (n)");
    scanf("%c", &c);
  }
  printf("Adios!");
  fclose(datos);
}

void ordenar_indice(Campo[] Indice, int n){
  // ordenando por codigo con bubble sort
  int i, j;
  bool swapped;
  for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - 1 - i; j++) {
            if (Indice[j].codigo > Indice[j + 1].codigo) {
                swap(&Indice[j], &Indice[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

void swap(Campo* a, Campo* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void actualizar_indice(struct TRegistro* reg, int cnt){
  Campo c;
  c.codigo = reg->codigo;
  c.RRN = cnt;
  indice[cnt] = c;
}

void serializar_registro(struct TRegistro* reg){
  FILE* datos = fopen("DATOS.dat", "wb+");
  fwrite(reg, sizeof(struct TRegistro), 1, datos);
  fclose(datos);
}

struct TRegistro* leer_registro(){
  char c;
  struct TRegistro reg;
  char[MAX_LINE_BUFFER] line_buffer;
  int i = 0;
  
  // Read name
  fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.nombre = line_buffer;
  clear_buffer(&buffer[0], MAX_LINE_BUFFER);
  
  // Read codigo
  fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.codigo = (int) atoi(&line_buffer[0]);
  clear_buffer(&buffer[0], MAX_LINE_BUFFER);

  // Read costo
  fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.costo = (int) atoi(&line_buffer[0]);
  clear_buffer(&buffer[0], MAX_LINE_BUFFER);

  // Read existencia minima
  fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.min = (int) atoi(&line_buffer[0]);
  clear_buffer(&buffer[0], MAX_LINE_BUFFER);  

  // Read existencias actuales
  fread(&c, sizeof(char), 1, regs);
  while(c !=  '\n'){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.act = (int) atoi(&line_buffer[0]);
  clear_buffer(&buffer[0], MAX_LINE_BUFFER);  
  return &reg;
}

void imprimir_registro(struct TRegistro* reg){
  printf("Registro\n");
  printf("Nombre: %s\n", reg->nombre);
  printf("Codigo: %s\n", reg->codigo);
  printf("Costo: %s\n", reg->costo);
  printf("Min: %s\n", reg->min);
  printf("Act: %s\n", reg->act);
}

void clear_buffer(char* buffer, int cap){
  for(int i = 0 ; i < cap +1;i++){
    buffer[i] = '\0';
  }
}
