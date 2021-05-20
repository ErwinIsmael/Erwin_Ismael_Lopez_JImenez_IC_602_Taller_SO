#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres deusuario a ingresar..."
   exit 1
fi


crearUsuario(){
	#echo "----> Crear Grupo <----"
	eval nombre="$1"
	eval password="$2"
	eval IDusuario="$3"
	eval IDgrupo="$4"
	eval infousuario="$5"
	eval directorio="$6"
	eval shell="$7"
	
	

if grep -q ${nombre} /etc/passwd 
then
	echo "Usuario [${nombre}] existe no se puede crear "
	echo " "
else 
	if grep -q ${IDgrupo} /etc/group
	then
		echo "Usuario [${nombre}] no existe: se creara nuevo usuario.... "
		echo " "
		echo "ID Grupo [${IDgrupo}] existente se puede crear usuario.... "
		echo " "
		useradd -c "${IDusuario} ${infousuario}"  -p "${password}" -d "${directorio}""${nombre}" -s "${shell}" "${nombre}"   -u  "${IDgrupo}" 
		echo "Usuario [${nombre}] creado satisfactoriamente..."
		echo " "
	else
		echo "ID Grupo [${IDgrupo}] no existe no se creo el usuario [${nombre}] ...." 
		echo " "
    fi	
fi	
 
}


while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
 
    crearUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
  
done < ${file}

exit 0

