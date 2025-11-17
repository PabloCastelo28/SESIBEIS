# SESIBEIS

Medidor de Decibéis com Arduino (Projeto de Empreendedorismo)
Este projeto consiste em um medidor de nível sonoro (SPL) utilizando um Arduino Nano e o sensor MAX9814, capaz de detectar variações de intensidade sonora e reagir de forma visual, sonora e mecânica.
Ele foi desenvolvido como parte de um projeto de empreendedorismo, unindo tecnologia, design e consciência sobre poluição sonora.

 Objetivo do Projeto

Criar um dispositivo capaz de:
Medir a intensidade sonora do ambiente em decibéis (dB)
Acender um LED de alerta quando o volume ultrapassar um limite configurado
Ativar um buzzer para sinalização sonora
Movimentar dois servos, simulando perninhas de um pequeno robô reagindo ao barulho
O foco é demonstrar como sensores e microcontroladores podem ser usados para monitoramento ambiental, além de promover educação em eletrônica e programação.

 Componentes Utilizados

Arduino Nano
Shield para Arduino Nano
Sensor de Microfone MAX9814 (AGC)
LED indicador
Buzzer ativo
2 Servomotores
Jumpers, protoboard (opcional) e fonte de alimentação

  Como Funciona

O MAX9814 capta o som do ambiente e envia um sinal analógico para o Arduino.
O Arduino converte esse sinal e calcula um valor proporcional em dB.
Quando o nível sonoro ultrapassa o limite configurado:
O LED acende
O buzzer apita
Os servos realizam um movimento pré-programado
Todo o comportamento pode ser ajustado no código, permitindo alterar limiares, velocidade dos servos e padrões de alerta.
