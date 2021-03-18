echo 'CONFIGURANDO RED...\n';
sleep 1s

echo '=====>Creando Puente<=====';
echo 'sudo nmcli conn add type bridge con-name br0 ifname br0';
#sudo nmcli conn add type bridge con-name br0 ifname br0
sleep 1s

echo '=====>Agregando br0 Como Interfaz<=====';
echo 'sudo nmcli conn add type ethernet slave-type bridge con-name bridge-br0 ifname enp3s0 master br0';
#sudo nmcli conn add type ethernet slave-type bridge con-name bridge-br0 ifname enp3s0 master br0
sleep 1s

echo '=====>Confirmando puente credo<=====';
echo 'Nota: si no aparece el BRIDGE "br0", sucedio algun error durante su creacion';
echo 'sudo nmcli conn show --active';
#sudo nmcli conn show --active
sleep 1s

echo '=====>Ingrese el nombre o direccion (UUID) del Bridge<=====';
read nameConn
echo 'sudo nmcli conn up '$nameConn;
#sudo nmcli conn up $nameConn
sleep 1s

echo '=====>Ingrese el nombre o direccion (UUID) del Ethernet<=====';
read nameConn1
echo 'sudo nmcli conn down '$nameConn1;
#sudo nmcli conn down $nameConn1
sleep 1s

echo '=====>La conexion Ethernet ahora deberia ser esclava del Puente-bridge<=====';
echo 'sudo nmcli conn show --active';
#sudo nmcli conn show --active
sleep 1s

#Configuracion de la red ad-hoc preliminar
echo 'sudo iw wlp2s0 set 4addr on';
#sudo iw wlp2s0 set 4addr on
sleep 1s

echo 'brctl addif enp3s0';
#brctl addif enp3s0
sleep 1s

echo 'brctl addif br0 wlp2s0 enp3s0';
#brctl addif br0 wlp2s0 enp3s0
sleep 1s

echo 'ip link set dev br0 up';
#ip link set dev br0 up
sleep 1s

echo 'brctl show';
#brctl show
sleep 1s

