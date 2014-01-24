Brouhaha
========

Brouhaha, le dispositif qui vous informe sur le niveau sonore autour de vous.


Code Arduino

Nécessite l'utilisation du dispositif de traitement du "Projet Decibel" : 

  *  Ce dispositif utilise arduino et transmet sur son port série(RX TX) la valeur mesurée par le sonomètre.

  *  Les données transitant sont de la forme < :058.:059.:068. etc >
      Structure :
                  < :XXX. > avec ":" caractère de début, "." caractère de fin, et "X" un chiffre.
  *  A chaque modification du niveau mesuré une trame est envoyée.
