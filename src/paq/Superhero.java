package paq;

public class Superhero {
  private String nombre;

  public Superhero(String nombre) {
    this.nombre = nombre;
  }
  
  public String saludo() {
    return "Soy " + nombre;
  }
}
