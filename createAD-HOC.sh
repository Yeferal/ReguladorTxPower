echo '';
#nameRed;
read -p "Escriba el nombre de la red: " nameRed;
#while[-z $nameRed]
#do
#echo '';
#read -p "Escriba el nombre de la red: " nameRed;
#done


echo '';
read -sp "Escriba la contraseña de la red: " passRed;


ruta='/etc/hostapd/';
rutaDnsMsq='/etc/dnsmasq.d/';

interfaceHost='interface=wlp2s0';
driverHost='driver=nl80211';
ssidHost='ssid='$nameRed;
bridgeHost='bridge=br0';
howmodeHost='hw_mode=g';
channelHost='channel=6';
macaddrHost='macaddr_acl=0';
ignoredHost='ignore_broadcast_ssid=0';
authHost='auth_algs=1';
wpaHost='wpa=3';
wpapassHost='wpa_passphrase='$passRed;
wpakeyHost='wpa_key_mgmt=WPA-PSK WPA-PSK-SHA256';
wpapairwiswHost='wpa_pairwise=TKIP';
rsnHost='rsn_pairwise=CCMP';

echo '';
echo 'rm my_wlan.conf';
rm my_wlan.conf

echo 'touch my_wlan.conf';
touch my_wlan.conf

#Escribiendo en el archivo
echo $interfaceHost >> my_wlan.conf;
echo $driverHost >> my_wlan.conf;
echo $ssidHost >> my_wlan.conf;
echo $bridgeHost >> my_wlan.conf;
echo $howmodeHost >> my_wlan.conf;
echo $channelHost >> my_wlan.conf;
echo $macaddrHost >> my_wlan.conf;
echo $ignoredHost >> my_wlan.conf;
echo $authHost >> my_wlan.conf;
echo $wpaHost >> my_wlan.conf;
echo $wpapassHost >> my_wlan.conf;
echo $wpakeyHost >> my_wlan.conf;
echo $wpapairwiswHost >> my_wlan.conf;
echo $rsnHost >> my_wlan.conf;

