var et=Object.create,T=Object.defineProperty,rt=Object.getPrototypeOf,at=Object.prototype.hasOwnProperty,nt=Object.getOwnPropertyNames,it=Object.getOwnPropertyDescriptor;var ct=t=>T(t,"__esModule",{value:!0});var ot=(t,s,e)=>{if(s&&typeof s=="object"||typeof s=="function")for(let r of nt(s))!at.call(t,r)&&r!=="default"&&T(t,r,{get:()=>s[r],enumerable:!(e=it(s,r))||e.enumerable});return t},N=t=>t&&t.__esModule?t:ot(ct(T(t!=null?et(rt(t)):{},"default",{value:t,enumerable:!0})),t);var l=t=>`[${t}m`,I={bold:l("1"),black:l("30"),red:l("31"),green:l("32"),yellow:l("33"),blue:l("34"),magenta:l("35"),cyan:l("36"),white:l("37"),gray:l("90"),bgBlack:l("40"),bgRed:l("41"),bgGreen:l("42"),bgYellow:l("43"),bgBlue:l("44"),bgMagenta:l("45"),bgCyan:l("46"),bgWhite:l("47"),bgGray:l("100"),reset:l("0")};function lt(t){return t.endsWith(I.reset)?t:`${t}${I.reset}`}var i=Object.keys(I).reduce((t,s)=>({...t,[s]:e=>lt(`${I[s]}${e}`)}),{});var c;(function(t){t[t.Enter=13]="Enter",t[t.Esc=27]="Esc",t[t.Space=32]="Space",t[t.Backspace=127]="Backspace",t[t.K0=48]="K0",t[t.K1=49]="K1",t[t.K2=50]="K2",t[t.K3=51]="K3",t[t.K4=52]="K4",t[t.K5=53]="K5",t[t.K6=54]="K6",t[t.K7=55]="K7",t[t.K8=56]="K8",t[t.K9=57]="K9",t[t.A=97]="A",t[t.B=98]="B",t[t.C=99]="C",t[t.D=100]="D",t[t.E=101]="E",t[t.F=102]="F",t[t.G=103]="G",t[t.H=104]="H",t[t.I=105]="I",t[t.J=106]="J",t[t.K=107]="K",t[t.L=108]="L",t[t.M=109]="M",t[t.N=110]="N",t[t.O=111]="O",t[t.P=112]="P",t[t.Q=113]="Q",t[t.R=114]="R",t[t.S=115]="S",t[t.T=116]="T",t[t.U=117]="U",t[t.V=118]="V",t[t.W=119]="W",t[t.X=120]="X",t[t.Y=121]="Y",t[t.Z=122]="Z",t[t.Up=65]="Up",t[t.Down=66]="Down",t[t.Right=67]="Right",t[t.Left=68]="Left",t[t.Home=69]="Home",t[t.End=70]="End",t[t.PgUp=71]="PgUp",t[t.PgDown=72]="PgDown"})(c||(c={}));var Q="[A",ut="[K",_=process.stdin;_.setRawMode(!0);_.setEncoding("utf8");async function Y(){return new Promise(t=>{_.once("data",s=>{switch(s){case"\r":t(13);break;case"":t(27);break;case"\x7F":t(127);break;case"[A":t(65);break;case"[B":t(66);break;case"[C":t(67);break;case"[D":t(68);break;case"[F":t(70);break;case"[H":t(69);break;case"[5~":t(71);break;case"[6~":t(72);break;case"":process.exit();default:s.match(/[ A-Za-z0-9]/)&&t(s.toLowerCase().charCodeAt(0))}})})}async function M(t,s,e=!0){let r=e?"\u2B05 e \u27A1":"\u2B07 e \u2B06",n=0,a=!1,o=i.blue("\xAB"),w=i.blue("\xBB");for(console.log(`
${t}`);!a;){let P=s.map((L,W)=>W!==n?` ${L} `:`${o}${L}${w}`).join(e?"":`
  `);console.log(`  ${P}`),console.log(i.gray(`   Use ${r} para escolher e \u21A9 para confirmar.`));let $=await Y();!e&&$===65||e&&$===68?n=n>0?n-1:s.length-1:!e&&$===66||e&&$===67?n=n<s.length-1?n+1:0:$===13&&(a=!0),E(e?2:1+s.length)}return E(2),_.removeAllListeners(),n}async function Z(t,s,e=!0){let r=e?"\u2B05 e \u27A1":"\u2B07 e \u2B06",n=[],a=0,o=!1,w=i.blue("\xAB"),P=i.blue("\xBB"),$=i.green("["),F=i.green("]");for(console.log(`
${t}`);!o;){let j=s.map((R,J)=>n[J]?`${$}${R}${F}`:J===a?`${w}${R}${P}`:` ${R} `).join(e?"":`
  `);console.log(`  ${j}`),console.log(i.gray(`   Use ${r} para escolher, 'espa\xE7o' para selecionar e \u21A9 para confirmar.`));let b=await Y();!e&&b===65||e&&b===68?a=a>0?a-1:s.length-1:!e&&b===66||e&&b===67?a=a<s.length-1?a+1:0:b===32?n[a]=!n[a]:b===13&&(o=!0),E(e?2:1+s.length)}return E(2),_.removeAllListeners(),n.reduce((j,b,B)=>n[B]?[...j,B]:j,[])}function E(t){console.log(`${Q}${ut}`.repeat(t)+Q)}var A="\u2665\u2666\u2663\u2660".split(""),X;(function(t){t[t.Heart=0]="Heart",t[t.Diamonds=1]="Diamonds",t[t.Clubs=2]="Clubs",t[t.Spades=3]="Spades"})(X||(X={}));var O=["2","3","4","5","6","7","8","9","10","J","Q","K","A"],x;(function(t){t[t.Two=0]="Two",t[t.Three=1]="Three",t[t.Four=2]="Four",t[t.Five=3]="Five",t[t.Six=4]="Six",t[t.Seven=5]="Seven",t[t.Eight=6]="Eight",t[t.Nine=7]="Nine",t[t.Ten=8]="Ten",t[t.Jack=9]="Jack",t[t.Queen=10]="Queen",t[t.King=11]="King",t[t.Ace=12]="Ace"})(x||(x={}));var p=class{constructor(s,e){if(typeof s=="string"){let r=A.reduce((o,w)=>s.indexOf(w)>o?s.indexOf(w):o,-1);if(r<0||r>=A.length)throw new Error(`Carta ${s} \xE9 inv\xE1lida: n\xE3o h\xE1 naipe.`);let n=s.substring(0,r),a=s.substring(r);if(this._value=O.findIndex(o=>o===n),this._suit=A.findIndex(o=>o===a),this._value<0||this._value>=O.length)throw new Error(`Carta ${s} \xE9 inv\xE1lida: valor inexistente.`)}else{if(e===void 0)throw new Error("Carta sem naipe associado.");this._value=s,this._suit=e}}get value(){return this._value}get suit(){return this._suit}get str(){return O[this._value]+A[this._suit]}toString(){let s=i.black(O[this._value]),e=this._suit<2?i.red(A[this._suit]):i.black(A[this._suit]);return i.bgWhite(s)+i.bgWhite(e)}};var m=class{constructor(s=[]){this.cards=s}get length(){return this.cards.length}shuffle(){for(let s=this.cards.length-1;s>0;s--){let e=Math.floor(Math.random()*(s+1));[this.cards[s],this.cards[e]]=[this.cards[e],this.cards[s]]}}sort(){this.cards.sort((s,e)=>s.suit!=e.suit?s.suit-e.suit:s.value-e.value)}get str(){return`[ ${this.cards.map(s=>s.str).join(" ")} ]`}toString(){return`[ ${this.cards.join(" ")} ]`}get top(){return this.cards[this.cards.length-1]}pop(){return this.cards.pop()}push(s){s!==void 0&&this.cards.push(s)}pushCards(s){s.forEach(e=>this.cards.push(e))}indexOf(s){return this.cards.findIndex(e=>e.value===s.value&&e.suit===s.suit)}has(s){return this.indexOf(s)>=0}hasAll(s){return s.every(e=>this.has(e))}remove(s){let e=this.indexOf(s);return e<0?!1:(this.cards.splice(e,1),!0)}removeCards(s){s.forEach(e=>this.remove(e))}clear(){this.cards=[]}merge(s){for(;s.length>0;)this.push(s.pop());return this.shuffle(),this}isMeld(){if(this.cards.length<3)return!1;let s=[],e=[],r=[];this.cards.forEach(a=>{a.value===12?s.push(a):a.value===0?r.push(a):e.push(a)}),e.sort((a,o)=>a.suit!=o.suit?a.suit-o.suit:a.value-o.value);let n=e[0].suit;if(r.length>2)return!1;if(r.length===2){if(r[0].suit!==n&&r[1].suit!==n)return!1;let a=r[0].suit===n?0:1;e.unshift(r.splice(a,1)[0])}if(s.length>2)return!1;s.length===2&&(e.unshift(s.shift()),e.push(s.pop()));for(let a=1;a<e.length;a++){if(n!==e[a].suit)return!1;let o=e[a].value-e[a-1].value;if(o===0||o>2)return!1;if(o===2){if(r.length===0)return!1;e.splice(a,0,r.shift());break}}if(s.length===1)if(e[0].value===0)e.unshift(s.pop());else if(e[e.length-1].value===11)e.push(s.pop());else if(r.length===1)e[0].value===1?(e.unshift(r.pop()),e.unshift(s.pop())):e[e.length-1].value===10&&(e.push(r.pop()),e.push(s.pop()));else return!1;return r.length===1&&e.unshift(r.pop()),this.cards=e,!0}};var ft=N(require("child_process")),H=N(require("stream")),z=N(require("readline"));function ht(t){let s=z.createInterface({input:t}),e=async function*(){for await(let r of s)yield r}();return async()=>(await e.next()).value}function V(){let t=new H.Readable({read:()=>{}});return process.on("message",s=>t.push(s)),{read:ht(t),write:s=>process.send(`${s}
`)}}function y(t,s,e){let r=Math.floor((t-s.length)/2)-1,n=e.repeat(r),a=t-r-s.length-2,o=e.repeat(a),w=i.white(`${n} ${s} ${o}`);console.log(i.bgBlue(w))}function C(t=""){let s=80;console.log();let e=i.white("=".repeat(s)),r=i.bgBlue(e);Array.isArray(t)?(console.log(r),t.forEach(n=>y(s,n," ")),console.log(r)):t.length==0?console.log(r):y(s,t,"="),console.log()}async function U(t){return new Promise(s=>setTimeout(s,t))}var gt=[i.cyan,i.yellow,i.magenta,i.cyan],v=console.log,f=V(),K=class{constructor(s,e){this.id=s;this.color=e}toString(){return this.color(this.id)}},pt={},G,tt,u,h,d,k,D=0;async function st(){return(await f.read()).split(" ").slice(1,-1).filter(t=>t.length>0)}function g(t=null){C(G),D=3,t&&(v(t),D++),v(`Voc\xEA possui as cartas ${u}`),v(h?`O topo da pilha de descarte \xE9 ${h}`:"A pilha de descarte est\xE1 vazia."),D+=2,d.length>0&&(v("Sua equipe tem os seguintes jogos na mesa:"),d.forEach(s=>v(s.toString())),D+=1+d.length),k.length>0&&(v("Seu advers\xE1rio tem os seguintes jogos na mesa:"),k.forEach(s=>v(s.toString())),D+=1+k.length)}function S(){E(D),D=0}async function mt(){tt=(await f.read()).split(" "),tt.forEach((t,s)=>pt[t]=new K(t,gt[s])),G=await f.read(),u=new m((await st()).map(t=>new p(t))),u.sort(),h=new p(await f.read()),d=[],k=[]}async function dt(){let t,s,e,r,n;for(;(t=await f.read())!==G;)do switch([s,...e]=(await f.read()).split(" "),s){case"GET_STOCK":break;case"GET_DISCARD":r=e.slice(1,-1).map(a=>new p(a)),r.push(h),n=new m(r),n.sort(),k.push(n),h=null;break;case"DISCARD":h=new p(e[0]);break;case"MELD_NEW":r=e.slice(1,-1).map(a=>new p(a)),n=new m(r),k.push(n);break;case"MELD_JOIN":r=e.slice(2,-1).map(a=>new p(a)),n=k[Number(e[0])],n.merge(new m(r));break;default:break}while(s!=="DISCARD")}async function wt(){S(),f.write("GET_STOCK");let t=await f.read(),s=new p(t);return u.push(s),u.sort(),g(`Voc\xEA puxou a carta ${s}`),!0}async function q(t){let s=u.cards.map(n=>n.toString()),e=await Z(t,s);return new m(e.map(n=>u.cards[n]))}async function bt(){let t=await q(`Com quais cartas voc\xEA far\xE1 jogo com ${h}?`);if(S(),t.length<2)return g(`Selecione pelo menos 2 cartas para formar um jogo com ${h}.`),!1;let s=new m([h,...t.cards]);if(s.isMeld()){f.write(`GET_DISCARD ${t.str}`);let r=(await st()).map(n=>new p(n));return u.removeCards(t.cards),u.pushCards(r),u.sort(),d.push(s),h=null,g(r.length>0?`O lixo tinha as seguintes cartas ${new m(r)}`:"N\xE3o tinha nenhuma carta na pilha de descarte al\xE9m da usada no jogo."),!0}else return g(`As cartas ${s} n\xE3o formam um jogo v\xE1lido.`),!1}async function xt(){let t=u.cards.map(r=>r.toString()),s=await M("Escolha uma carta para descartar.",t),e=u.cards[s];S(),f.write(`DISCARD ${e.str}`),h=e,u.remove(e)}async function $t(){let t=await q("Quais cartas do jogo voc\xEA quer baixar?");S(),t.isMeld()?(f.write(`MELD_NEW ${t.str}`),await U(50),u.removeCards(t.cards),d.push(t),g("Jogo baixado")):g(`${t} n\xE3o forma um jogo v\xE1lido.`)}async function vt(){if(d.length>0){let t=d.map(r=>r.toString()),s=await M("Em qual jogo voc\xEA baixar cartas?",t,!1),e=await q(`Quais cartas ser\xE3o adicionadas no jogo ${t[s]}`);if(S(),e.length>0){let r=d[s];r.pushCards(e.cards),r.isMeld()?(f.write(`MELD_JOIN ${s} ${e.str}`),await U(50),u.removeCards(e.cards),g(`Cartas ${e} adicionadas no jogo ${r}.`)):(r.removeCards(e.cards),g(`A jun\xE7\xE3o de ${e} com ${r} n\xE3o forma um jogo v\xE1lido.`))}else g("Nenhuma carta selecionada. Pressione espa\xE7o para adicionar/remover uma carta durante a sele\xE7\xE3o.")}else S(),g("N\xE3o h\xE1 jogo para adicionar cartas")}async function kt(){let t=!1;do switch(await M("\xC9 sua vez! Voc\xEA come\xE7a puxando uma carta. De onde voc\xEA quer puxar?",["Do deque de compra","Da pilha de descarte (fazendo um jogo com a carta do topo)"],!1)){case 0:t=await wt();break;case 1:t=await bt();break}while(!t)}async function Dt(){let t;do switch(t=await M("O que deseja fazer agora?",["Descartar uma carta (e finalizar a jogada)","Baixar um jogo na mesa","Adicionar cartas num jogo"],!1),t){case 0:await xt();break;case 1:await $t();break;case 2:await vt();break}while(t!==0)}async function Et(){g(),await kt(),await Dt()}async function At(){for(await mt();;)await dt(),await Et()}process.send?At():console.log(`
    Este script substitui um bot no Buraco, interagindo com o usu\xE1rio nas tomadas
    de decis\xE3o. Ele n\xE3o foi feito para ser executado de forma independente.
    `);
