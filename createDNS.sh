
rutaDnsMsq='/etc/dnsmasq.d/';

interfaceDns='interface=wlp2s0';
dhcpDns='dhcp-range=10.0.0.3,10.0.0.254,12h';
noresolvDns='no-resolv';
server1Dns='server=8.8.8.8';
server2Dns='server=8.8.4.4';

echo 'rm my_dnsmsq.conf';
rm my_dnsmsq.conf

echo 'touch my_dnsmsq.conf';
touch my_dnsmsq.conf

#Escribiendo en el archivo
echo $interfaceDns >> my_dnsmsq.conf;
echo $dhcpDns >> my_dnsmsq.conf;
echo $noresolvDns >> my_dnsmsq.conf;
echo $server1Dns >> my_dnsmsq.conf;
echo $server2Dns >> my_dnsmsq.conf;