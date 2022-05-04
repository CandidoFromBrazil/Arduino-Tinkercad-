#define ledR 2 // definindo variáveis com o endereço das portas digitais do Arduino;
#define ledG 4
#define ledB 3
#define botao 7

class Btn{ //1° classe, responsável pelo botão(ligado na porta 7 do Arduino(INPUT));
public: //define (toda parametro, metodo abaixo desse ponto), como publico, podendo especificar se o método ou o parametro é privado;  (public metodo construtor)
  int btnclicado,btnliberado,pino; //parametros da classe Btn;
  Btn(int p){ //(metodo construtor)-forma de método construtor clássica; Com parametro (p) passado;
    pino=p;//a variável de classe local(pino) rescebe o parametro(p)
    btnclicado=btnliberado=0; //as variáveis btnclicado e btnliberado são inicializadas valendo 0;
  }
  bool press(){ //criação do metodo(press)<do tipo bool>=<retorna boll>
  if(digitalRead(pino)==HIGH){ //condição(digitalRead(pino) = o valor da variável(pino) vai ser lido pelo arduino(digitalRead(INPUT)) e será comparado, if(HIGH), execultar; HIGH = 1, LOW=0;
    btnclicado=1; //pino(porta do botão(passada pelo parametro(p) na instanciação após o final da classe) em (HIGH),  significa que está passando corrente;Lembrar que o botão está em (pull down);
    btnliberado=0;
  }else{ //else ativando assim que libera o botão, garantindo que o botão foi liberado, ele troca o valor de(btnliberado=0), para 1 (dados bool);
    btnliberado=1;
  }
  if((btnclicado==1)and(btnliberado==1)){ // condição de retorno, que checa os estados do botão, garantindo que btnclicado e btnliberado controle o estado do botão(garantindo que mantenha a cor) até a proxima chamada;
  btnclicado=0; //reiniciando os valores das variáveis, para garantir que sejam execultadas apropiadamente quando forem chamadas novamente(ao precionar e liberar o botão);
  btnliberado=0;
  return true; //(btnclicado==1)and(btnliberado==1), retorna true;
  }else{
    return false; //else: false;
  }
 }
}; //fim da classe Btn;
Btn btn(botao); //instanciando um objeto na classe Btn; (<classe> <objeto(parametro da classe(p no caso))> com o valor d(#define botao)

class Cor{ //2° classe, responsável pelas cores dos leds, ledR,ledG,ledB(ligadas na porta 2,4,3 do Arduino(OUTPUT));
public: //define (toda parametro, metodo abaixo desse ponto), como publico, podendo especificar se o método ou o parametro é privado;  (public metodo construtor)
  int pinoR,pinoG,pinoB,ciclo,maximo; //parametros da classe Cor;
  Cor(int pr, int pg, int pb):pinoR(pr),pinoG(pg),pinoB(pb){ //iniciando e parametros do metodo/o construtor; referindo os parametros do método(v.locais) recebendo valores das (v.globais);
    ciclo=0; // tambem referindo os valores das demais variáveis
    maximo=3;
  }
  void trocaled(){ //metodo publico
    if(ciclo==0){ //condições para controle do ciclo de cores nos leds;
      corled(1,0,0); //método(trocaled), chamando o metodo PRIVADO(corled(parametros)) em sua condição if, e preenchendo com valores(bool) seus parametros;
    }else if(ciclo==1){
      corled(0,1,0);
    }else if(ciclo==2){
      corled(0,0,1);
    }
    ciclo++; //incremento, o que garante que as condiçãoes (if,else if e else) possam ser acessadas;
    if(ciclo>maximo-1){ // codição que garante a correta repetição do metodo(trocaled);
      ciclo=0; //ciclo volta a receber 0 para que possa ser reutilizado no metodo;
    }
  }  
private: //declarando que o método a seguir é privado;
  void corled(int r, int g, int b){//construção do metodo(corled);
    digitalWrite(pinoR,r); //digitalWrite(<v.global>,<parametros(v.locais)>; Quando o metodo(trocaled()) chamar corled(parametros), ele irá preencher os parametros de corled(parametros), e digitalWrite irá garantir que esse método realizará uma ação(ligar o led na cor desejada) quando for chamado por trocaled();
    digitalWrite(pinoG,g);
    digitalWrite(pinoB,b);
  }
}; //fim da classe Cor;
Cor cor(ledR,ledG,ledB); //instanciando um objeto na classe Cor; (<classe> <objeto(parametro da classe(pinoR,pinoG,pinoB))>, com os valores dos(#define ledR,ledG,ledB);


void setup() { //Definindo o "Hardware" a ser utilizado e seu modo de uso pretendido;
  pinMode(ledR,OUTPUT);//pinMode=definindo porta do Arduino; pinMode(<n.da porta>,<uso pretendido>); OUTPUT = PORTA DO ARDUINO SETADA PARA REALIZAR UMA AÇÂO; INPUT = PORTA DO ARDUINO SETADA PARA RESCEBE UMA AÇÂO;
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(botao,INPUT);
}

void loop() { //Definindo o "RunTime" método que faz o programa ligar mesmo( e seu código de funcionamento); (repete em loop)
  if(btn.press())//Condição de chamada do metodo(press), do objeto(btn), instanciado na classe(Btn);
  cor.trocaled(); //Uma vez que a condição do botão(Btn.press) sejá verdadeira, O objeto(cor.trocaled()) será chamado;
}
//btn.press retorna (true), chamando o metodo(trocaled) do objeto(cor), instanciado na classe(Cor);
