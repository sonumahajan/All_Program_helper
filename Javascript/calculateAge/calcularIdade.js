function calculaIdade(dataNasc) {
  const dataAtual = new Date();
  const anoAtual = dataAtual.getFullYear();
  const anoNascParts = dataNasc.split('/');
  const diaNasc = anoNascParts[0];
  const mesNasc = anoNascParts[1];
  const anoNasc = anoNascParts[2];
  let idade = anoAtual - anoNasc;
  const mesAtual = dataAtual.getMonth() + 1;

  if (mesAtual < mesNasc) {
    idade--;
  } else if (mesAtual == mesNasc) {
    if (new Date().getDate() < diaNasc) {
      idade--;
    }
  }
  return idade;
}

export default calculaIdade;
