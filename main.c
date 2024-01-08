#include <stdio.h>

const int TOTAL_REGISTROS = 10;
typedef struct 
{ 
    char[40] nombre;
    char[4] codigo;
} TRegistro; 

typedef struct 
{ 
    int RRN;
    char[4] codigo;
} Campo; 
const Campo[TOTAL_REGISTROS] Indice;

void main(){
  //1. Escribe archivo Registros.txt
  //2. Crear archivo binario DATOS.dat en modo escritura
  FILE* datos = fopen("DATOS.dat", "wb");
  fclose(datos);
  FILE* regs = fopen("Registros.txt", "r");

  struct TRegsitro reg;
  
  int cnt = 0;
  while(cnt < 10){
    &reg = leer_registro();
    serializar_registro(&reg);
    actualizar_indice(&reg, cnt);  
    cnt++;
  }
  fclose(regs);
}
 void actualizar_indice(struct TRegistro* reg, int cnt){
   struct Campo c;
   c.RRN = cnt
   c.codigo = reg->codigo;
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
  char[15] line_buffer;
  int i = 0;
  // Read name
  fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.nombre = line_buffer;
  clear_buffer(&buffer[0], 15);
// Read codigo
fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.nombre = line_buffer;
  clear_buffer(&buffer[0], 15);

  // Read codigo
fread(&c, sizeof(char), 1, regs);
  while(c !=  ','){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.codigo = line_buffer;
  clear_buffer(&buffer[0], 15);  
}

// Read last field
fread(&c, sizeof(char), 1, regs);
  while(c !=  '\n'){
    line_buffer[i++] = c;
    fread(&c, sizeof(char), 1, regs);
  }
  line_buffer[i] = '\0';
  TRegistro.last_element = line_buffer;
  clear_buffer(&buffer[0], 15);


  return &reg;
}

void clear_buffer(char* buffer, int cap){
  for(int i = 0 ; i< cap +1;i++){
    buffer[i] = '\0';
  }
}
