cuivre<-read.table("cuivre.txt",sep=" ")
fer<-read.table("fer.txt",sep=" ")
verre<-read.table("verre.txt",sep=" ")
polystyrene<-read.table("polystyrene.txt",sep=" ")

plot(cuivre,xlab="x",ylab="chaleur",pch=4,col="green",main = "cuivre", ylim = c(12,25))+
plot(fer,xlab="x",ylab="chaleur",pch=4,col="red", main = "fer", ylim = c(12,25))+
plot(verre,xlab="x",ylab="chaleur",pch=4,col="blue", main = "verre", ylim = c(12,25))+
plot(polystyrene,xlab="x",ylab="chaleur",pch=4,col="gray", main = "polystyrene", ylim = c(12,25))

str("code R")