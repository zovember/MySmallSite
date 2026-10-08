#include <iostream>


namespace html_game {
  
    std::string html_game = R"(<!DOCTYPE html>
      <html>
      <head>
        <title>Ping Pong</title>
        <meta charset="UTF-8">
        <style>
        html, body {
          height: 100%;
          margin: 0;
        }

        body {
          background: black;
          display: flex;
          align-items: center;
          justify-content: center;
        }
        </style>
      </head>
      <body>
      <canvas width="750" height="585" id="game"></canvas>
      <div id="ball_speed">3</div>
      <script>
      const canvas = document.getElementById('game');
      const context = canvas.getContext('2d');
      const grid = 15;
      const paddleHeight = grid * 5; // 80
      const maxPaddleY = canvas.height - grid - paddleHeight;

      var paddleSpeed = 6;
      var ballSpeed = 3;
      var ctr_ball_speed = 0;

      const leftPaddle = {
        // start in the middle of the game on the left side
        x: grid * 2,
        y: canvas.height / 2 - paddleHeight / 2,
        width: grid,
        height: paddleHeight,

        // paddle velocity
        dy: 0
      };
      const rightPaddle = {
        // start in the middle of the game on the right side
        x: canvas.width - grid * 3,
        y: canvas.height / 2 - paddleHeight / 2,
        width: grid,
        height: paddleHeight,

        // paddle velocity
        dy: 0
      };
      const ball = {
        // start in the middle of the game
        x: canvas.width / 2,
        y: canvas.height / 2,
        width: grid,
        height: grid,

        // keep track of when need to reset the ball position
        resetting: false,

        // ball velocity (start going to the top-right corner)
        dx: ballSpeed,
        dy: -ballSpeed
      };

      // check for collision between two objects using axis-aligned bounding box (AABB)
      // @see https://developer.mozilla.org/en-US/docs/Games/Techniques/2D_collision_detection
      function collides(obj1, obj2) {
        return obj1.x < obj2.x + obj2.width &&
              obj1.x + obj1.width > obj2.x &&
              obj1.y < obj2.y + obj2.height &&
              obj1.y + obj1.height > obj2.y;
      }

      // game loop
      function loop() {
        requestAnimationFrame(loop);
        context.clearRect(0,0,canvas.width,canvas.height);

        // move paddles by their velocity
        leftPaddle.y += leftPaddle.dy;
        rightPaddle.y += rightPaddle.dy;

        // prevent paddles from going through walls
        if (leftPaddle.y < grid) {
          leftPaddle.y = grid;
        }
        else if (leftPaddle.y > maxPaddleY) {
          leftPaddle.y = maxPaddleY;
        }

        if (rightPaddle.y < grid) {
          rightPaddle.y = grid;
        }
        else if (rightPaddle.y > maxPaddleY) {
          rightPaddle.y = maxPaddleY;
        }

        // draw paddles
        context.fillStyle = 'white';
        context.fillRect(leftPaddle.x, leftPaddle.y, leftPaddle.width, leftPaddle.height);
        context.fillRect(rightPaddle.x, rightPaddle.y, rightPaddle.width, rightPaddle.height);

        // move ball by its velocity
        ball.x += ball.dx;
        ball.y += ball.dy;

        // prevent ball from going through walls by changing its velocity
        if (ball.y < grid) {
          ball.y = grid;
          ball.dy *= -1;
        }
        else if (ball.y + grid > canvas.height - grid) {
          ball.y = canvas.height - grid * 2;
          ball.dy *= -1;
        }

        // reset ball if it goes past paddle (but only if we haven't already done so)
        if ( (ball.x < 0 || ball.x > canvas.width) && !ball.resetting) {
          ctr_ball_speed = 0;
          ball.resetting = true;

          // give some time for the player to recover before launching the ball again
          setTimeout(() => {
            ball.resetting = false;
            ball.x = canvas.width / 2;
            ball.y = canvas.height / 2;
          }, 400);
        }

        // check to see if ball collides with paddle. if they do change x velocity
        if (collides(ball, leftPaddle)) {
          ball.dx *= -1;

          // move ball next to the paddle otherwise the collision will happen again
          // in the next frame
          ball.x = leftPaddle.x + leftPaddle.width;

          ctr_ball_spped += 1;
          if (ctr_ball_speed % 3 == 0) {
            ball_speed += 1;
          }
        }
        else if (collides(ball, rightPaddle)) {
          ball.dx *= -1;

          // move ball next to the paddle otherwise the collision will happen again
          // in the next frame
          ball.x = rightPaddle.x - ball.width;
        }

        // draw ball
        context.fillCircle(ball.x, ball.y, ball.width, ball.height);

        // draw counter ball speed


        // draw walls
        context.fillStyle = 'lightgrey';
        context.fillRect(0, 0, canvas.width, grid);
        context.fillRect(0, canvas.height - grid, canvas.width, canvas.height);

        // draw dotted line down the middle
        for (let i = grid; i < canvas.height - grid; i += grid * 2) {
          context.fillRect(canvas.width / 2 - grid / 2, i, grid, grid);
        }
      }

      // listen to keyboard events to move the paddles
      document.addEventListener('keydown', function(e) {

        // up arrow key
        if (e.which === 38) {
          rightPaddle.dy = -paddleSpeed;
        }
        // down arrow key
        else if (e.which === 40) {
          rightPaddle.dy = paddleSpeed;
        }

        // w key
        if (e.which === 87) {
          leftPaddle.dy = -paddleSpeed;
        }
        // a key
        else if (e.which === 83) {
          leftPaddle.dy = paddleSpeed;
        }
      });

      // listen to keyboard events to stop the paddle if key is released
      document.addEventListener('keyup', function(e) {
        if (e.which === 38 || e.which === 40) {
          rightPaddle.dy = 0;
        }

        if (e.which === 83 || e.which === 87) {
          leftPaddle.dy = 0;
        }
      });

      // start the game
      requestAnimationFrame(loop);
      </script>
      </body>
      </html>)";

    std::string html_prism = R"(<!doctype html>
      <html lang="ru">
      <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Сечения правильной треугольной призмы — интерактивная геометрия</title>
        <meta name="description" content="Вращайте правильную треугольную призму, ставьте три точки на рёбрах или гранях и исследуйте получившееся сечение.">
        <link rel="icon" type="image/svg+xml" href="data:image/svg+xml,%3Csvg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 32 32'%3E%3Crect width='32' height='32' rx='8' fill='%2310192b'/%3E%3Cpath d='m16 5 10 6v11l-10 6-10-6V11Z M6 11l10 6 10-6 M16 17v11' fill='none' stroke='%239caeff' stroke-width='2'/%3E%3Cpath d='m6 16 15-8 5 10-10 6Z' fill='%23ff936d' fill-opacity='.8'/%3E%3C/svg%3E">
        <style>
          :root{color-scheme:light;--ink:#172037;--muted:#626e83;--line:#e0e5ed;--purple:#5c58de;--orange:#ff9a76;--bg:#f4f6fa;--radius:18px;font-family:Inter,-apple-system,BlinkMacSystemFont,"Segoe UI",Arial,sans-serif;font-synthesis:none}
          *{box-sizing:border-box}body{margin:0;background:var(--bg);color:var(--ink)}button,input,select{font:inherit}button,select,input[type=range]{cursor:pointer}button{color:inherit}button:focus-visible,select:focus-visible,input:focus-visible,canvas:focus-visible{outline:3px solid #7973fc;outline-offset:4px}button{transition:background .15s,border-color .15s,transform .15s}button:active:not(:disabled){transform:translateY(1px)}button:disabled{opacity:.4;cursor:default}button svg{pointer-events:none}svg{display:block}a{color:inherit}.sr-only{position:absolute;width:1px;height:1px;overflow:hidden;clip:rect(0,0,0,0);white-space:nowrap}
          .shell{max-width:1700px;margin:auto;padding:28px 32px 22px}.header{display:flex;align-items:center;justify-content:space-between;gap:20px;margin-bottom:26px}.brand{display:flex;align-items:center;gap:14px}.logo{width:48px;height:48px;border-radius:14px;background:#171e32;display:grid;place-items:center;flex-shrink:0}.eyebrow{font-size:12px;line-height:1.4;font-weight:650;letter-spacing:.12em;color:#6c7487;text-transform:uppercase;margin-bottom:3px}h1{font-size:24px;letter-spacing:-.7px;line-height:1.2;margin:0;font-weight:700}.header-note{font-size:14px;color:var(--muted);display:flex;align-items:center;gap:8px}.header-note .dot{width:6px;height:6px;border-radius:50%;background:#8a83ea}.workspace{display:grid;grid-template-columns:minmax(0,1fr) 340px;gap:20px;align-items:stretch}.stage{position:relative;background:#101827;border:1px solid #253049;border-radius:var(--radius);min-height:660px;height:calc(100dvh - 158px);max-height:940px;overflow:hidden;color:#eaf0ff;isolation:isolate}.stage:before{content:"";position:absolute;inset:0;background:radial-gradient(ellipse at 50% 38%,#1d2945 0%,#111a2b 50%,#0e1625 100%);z-index:-1}.stage canvas{width:100%;height:100%;display:block;touch-action:none;cursor:grab}.stage canvas.dragging{cursor:grabbing}.stage canvas.placing{cursor:crosshair}.stage-top{position:absolute;left:24px;right:24px;top:23px;display:flex;justify-content:space-between;gap:10px;align-items:flex-start;pointer-events:none}.stage-tag{font-size:12px;font-weight:600;letter-spacing:.13em;color:#93a1bd;margin:4px 0 9px}.stage-title{font-size:16px;color:#d8e0f0;font-weight:500}.view-badge{display:flex;gap:7px;align-items:center;background:#202b40;border:1px solid #334059;border-radius:7px;padding:6px 9px;font-size:12px;color:#bec9df}.stage-bottom{position:absolute;left:24px;bottom:23px;right:24px;display:flex;justify-content:space-between;gap:14px;align-items:flex-end;pointer-events:none}.hints{font-size:13px;color:#a7b3c9;line-height:1.9}.hint-line{display:flex;gap:8px;align-items:center}.hint-line svg{width:15px;height:15px;color:#7f8eaa;flex-shrink:0}.view-controls{display:flex;gap:6px;pointer-events:auto}.icon-button{display:grid;place-items:center;border:1px solid #344158;border-radius:10px;width:38px;height:38px;color:#cad5e9;background:#202b40}.icon-button:hover{background:#303e56;border-color:#536481}.divider{width:1px;background:#354057;margin:7px 4px}.toast{position:absolute;left:50%;bottom:113px;transform:translateX(-50%);max-width:calc(100% - 38px);width:max-content;padding:10px 16px;background:#25324b;border:1px solid #495a79;border-radius:10px;font-size:14px;box-shadow:0 6px 24px #0003;pointer-events:none;opacity:0;transition:opacity .15s}.toast.show{opacity:1}.side{display:flex;flex-direction:column;gap:16px}.card{background:white;border:1px solid var(--line);border-radius:var(--radius);padding:22px}.card-head{display:flex;align-items:center;justify-content:space-between;gap:8px;margin-bottom:9px}h2{font-size:18px;font-weight:650;margin:0;letter-spacing:-.35px}.count{font-size:13px;color:#777f91;font-variant-numeric:tabular-nums}.intro{font-size:14px;line-height:1.6;color:var(--muted);margin:0 0 18px}.segmented{display:flex;padding:4px;border-radius:10px;background:#eef1f6;margin-bottom:20px;gap:3px}.segmented button{flex:1;border:0;background:none;color:#657088;padding:9px 4px;border-radius:7px;font-size:14px;font-weight:550}.segmented button[aria-pressed=true]{background:white;color:#222d43;box-shadow:0 1px 4px #14224417}.point-row{border:1px solid #e2e7ef;background:white;border-radius:12px;margin-bottom:10px;overflow:hidden;transition:border-color .15s,background .15s}.point-row.active{border-color:#9189f0;background:#f7f6ff}.point-top{display:flex;align-items:center;gap:10px;padding:12px}.point-pick{display:flex;align-items:center;gap:10px;flex:1;min-width:0;background:none;border:0;text-align:left;padding:0}.point-letter{width:32px;height:32px;display:grid;place-items:center;flex-shrink:0;border-radius:9px;background:#f0edfe;color:#6055c7;font-size:15px;font-weight:700}.point-row[data-set=true] .point-letter{background:#fff0e8;color:#ab4924}.point-text{font-size:14px;line-height:1.3;display:block;font-weight:550}.point-sub{font-size:12px;display:block;line-height:1.5;color:#798298;margin-top:2px}.remove{font-size:21px;color:#8d94a5;border:0;background:none;padding:2px 5px;line-height:1}.remove:hover{color:#cb4827}.edge-controls{display:flex;gap:8px;align-items:center;padding:0 12px 12px}.edge-select{font-size:14px;color:#4d5670;border:1px solid #dce1ed;border-radius:7px;background:white;padding:5px;width:100%;min-width:0}.percent{font-size:12px;color:#68738a;width:36px;text-align:right;font-variant-numeric:tabular-nums}.point-slider{width:100%;min-width:30px;accent-color:#7a6bdf}.snap-row{display:flex;gap:9px;align-items:center;font-size:13px;color:#657088;line-height:1.5;margin:15px 0 0}.snap-row input,.option input{accent-color:#7064d9;width:16px;height:16px;margin:0;flex-shrink:0}.actions{display:flex;gap:8px;margin-top:20px}.button{padding:11px 10px;border:1px solid var(--line);border-radius:9px;background:white;font-size:14px;font-weight:550;display:flex;align-items:center;justify-content:center;gap:6px}.button:hover{background:#f1f3f8}.button.primary{background:#6559d9;color:white;border-color:#6559d9;flex:1}.button.primary:hover{background:#564bc3}.result-card{flex:1;min-height:210px;display:flex;flex-direction:column}.result-head{display:flex;align-items:center;gap:8px;margin-bottom:11px}.section-dot{width:9px;height:9px;border-radius:3px;background:#ee946f}.result-state{font-size:14px;color:var(--muted);line-height:1.65;margin:0}.result-state.error{color:#a9442f}.mini-wrap{position:relative;flex:1;min-height:115px;padding:5px 0 9px;display:flex;align-items:center;justify-content:center}.mini-svg{width:100%;max-height:130px;height:125px;overflow:visible}.empty-section{width:100%;text-align:center;color:#8b95a8;padding:22px 8px;font-size:13px;line-height:1.65}.empty-section svg{margin:0 auto 10px;color:#afb7c7}.result-foot{font-size:12px;color:#8690a2;text-align:center;margin-top:2px}.option{display:flex;align-items:center;gap:8px;padding-top:15px;border-top:1px solid #e8ebf2;font-size:14px;color:#687187}.footer{display:flex;justify-content:space-between;gap:18px;padding:17px 3px 0;font-size:12px;color:#80899b}.footer-key{font-family:inherit;background:white;border:1px solid #dce1eb;border-radius:4px;padding:1px 4px;font-size:11px}.mobile-help{display:none}
          @media(min-width:1500px){.workspace{grid-template-columns:minmax(0,1fr) 370px}.card{padding:25px}.stage{min-height:740px}}
          @media(max-width:1000px){.shell{padding:22px}.workspace{grid-template-columns:minmax(0,1fr) 310px;gap:15px}.card{padding:18px}.stage{min-height:670px}.stage-top,.stage-bottom{left:18px;right:18px}.header-note{display:none}.hint-desktop{display:none}.hints{font-size:12px}.stage-bottom{align-items:flex-end}.view-controls{gap:4px}.icon-button{width:34px;height:34px}.divider{margin-left:1px;margin-right:1px}}
          @media(max-width:740px){.shell{padding:18px 14px}.header{margin-bottom:18px}h1{font-size:22px}.eyebrow{font-size:10px}.logo{width:42px;height:42px;border-radius:12px}.workspace{display:flex;flex-direction:column;gap:14px}.stage{height:61dvh;min-height:430px;max-height:630px;width:100%;border-radius:15px}.stage-top{top:17px}.stage-tag{font-size:10px}.stage-title{font-size:14px}.stage-bottom{bottom:15px}.hint-line{display:none}.mobile-help{display:block;font-size:12px;color:#a7b3c9;line-height:1.7;max-width:160px}.side{display:grid;grid-template-columns:1fr;gap:14px}.card{padding:19px}.intro{margin-bottom:15px}.segmented{margin-bottom:15px}.point-row{margin-bottom:8px}.point-top{padding:10px 12px}.result-card{min-height:240px}.mini-wrap{min-height:130px}.footer{display:block;line-height:1.8}.footer .keys{display:none}.toast{bottom:95px;font-size:13px}.view-controls{gap:5px}.icon-button{width:34px;height:36px}}
          @media(prefers-reduced-motion:reduce){*{transition:none!important;scroll-behavior:auto!important}}
        </style>
      </head>
      <body>
      <div class="shell">
        <header class="header">
          <div class="brand"><div class="logo" aria-hidden="true"><svg width="30" height="32" viewBox="0 0 32 34"><path d="m16 3 12 7v14l-12 7-12-7V10Z M4 10l12 7 12-7 M16 17v14" fill="none" stroke="#b7c2ff" stroke-width="1.6" stroke-linejoin="round"/><path d="m4 17 18-10 6 14-12 5Z" fill="#ff9a76" fill-opacity=".8"/></svg></div><div><div class="eyebrow">Интерактивная геометрия</div><h1>Сечения треугольной призмы</h1></div></div>
          <div class="header-note"><span class="dot"></span>Три точки. Одна плоскость.</div>
        </header>
        <main class="workspace">
          <section class="stage" aria-label="Вращаемая модель правильной треугольной призмы">
            <canvas id="scene" tabindex="0" aria-label="Правильная треугольная призма ABC A₁B₁C₁. Клик — поставить точку; перетаскивание — вращать. Стрелки — вращать, плюс и минус — масштаб. Точки также можно выбрать в панели справа." aria-describedby="canvas-help"></canvas>
            <div class="stage-top"><div><div class="stage-tag">Правильная треугольная призма ABC · A₁B₁C₁</div><div class="stage-title" id="stage-title">Поставьте первую точку</div></div><div class="view-badge"><svg width="13" height="13" viewBox="0 0 16 16" aria-hidden="true"><path d="m8 1 6 3.5v7L8 15l-6-3.5v-7ZM2 4.5 8 8l6-3.5M8 8v7" fill="none" stroke="currentColor" stroke-width="1.2"/></svg>3D</div></div>
            <div id="toast" class="toast" role="status"></div>
            <div class="stage-bottom">
              <div class="hints" id="canvas-help"><div class="hint-line"><svg viewBox="0 0 20 20" fill="none" stroke="currentColor" stroke-width="1.3" aria-hidden="true"><rect x="5" y="2" width="10" height="16" rx="5"/><path d="M10 2v6M5 8h10"/></svg>Потяните, чтобы вращать</div><div class="hint-line"><svg viewBox="0 0 20 20" fill="none" stroke="currentColor" stroke-width="1.3" aria-hidden="true"><path d="m5 2 11 9-6 1-3 5Z"/></svg>Клик — точка<span class="hint-desktop"> · колесо — масштаб</span></div><div class="mobile-help">Потяните — вращение<br>Коснитесь — точка</div></div>
              <div class="view-controls"><button class="icon-button" id="zoom-out" title="Уменьшить" aria-label="Уменьшить"><svg width="16" height="16" viewBox="0 0 20 20"><path d="M4 10h12" stroke="currentColor" stroke-width="1.6"/></svg></button><button class="icon-button" id="zoom-in" title="Увеличить" aria-label="Увеличить"><svg width="16" height="16" viewBox="0 0 20 20"><path d="M4 10h12M10 4v12" stroke="currentColor" stroke-width="1.6"/></svg></button><span class="divider"></span><button class="icon-button" id="home" title="Исходный ракурс" aria-label="Исходный ракурс"><svg width="18" height="18" viewBox="0 0 20 20" fill="none" stroke="currentColor" stroke-width="1.5"><path d="M4 8a6.5 6.5 0 1 1-.3 5M4 3v5h5" stroke-linecap="round" stroke-linejoin="round"/></svg></button></div>
            </div>
          </section>
          <aside class="side" aria-label="Построение сечения">
            <section class="card"><div class="card-head"><h2>Выберите три точки</h2><span class="count" id="count">0 / 3</span></div><p class="intro" id="placement-hint">Нажмите на ребро призмы. Сечение появится после третьей точки.</p>
              <div class="segmented" role="group" aria-label="Где размещать точки"><button id="mode-edges" aria-pressed="true">На рёбрах</button><button id="mode-faces" aria-pressed="false">На гранях</button></div>
              <div id="points"></div>
              <label class="snap-row"><input type="checkbox" id="snap" checked>Привязка к серединам рёбер</label>
              <div class="actions"><button class="button primary" id="example">Показать пример</button><button class="button" id="clear" disabled>Сбросить</button></div>
            </section>
            <section class="card result-card"><div class="result-head"><span class="section-dot"></span><h2>Сечение</h2></div><p class="result-state" id="result-status" aria-live="polite">Ждём три точки</p><div class="mini-wrap" id="mini"><div class="empty-section"><svg width="56" height="44" viewBox="0 0 56 44" fill="none" aria-hidden="true"><path d="m8 33 12-24 28 17Z" stroke="currentColor" stroke-dasharray="4 4" stroke-width="1.3"/><circle cx="8" cy="33" r="3" fill="#a9a1e4"/><circle cx="20" cy="9" r="3" fill="#a9a1e4"/><circle cx="48" cy="26" r="3" fill="#a9a1e4"/></svg>Здесь появится фигура сечения</div></div><label class="option"><input type="checkbox" id="plane">Показать всю плоскость</label></section>
          </aside>
        </main>
        <footer class="footer"><span>Выберите точку M, N или K в панели, чтобы переставить её.</span><span class="keys"><kbd class="footer-key">←</kbd> <kbd class="footer-key">↑</kbd> <kbd class="footer-key">↓</kbd> <kbd class="footer-key">→</kbd> вращение · <kbd class="footer-key">Esc</kbd> отмена выбора</span></footer>
      </div>
      <script>
      'use strict';
      // Geometry is computed in prism coordinates independently of the view.
      const Geometry = (() => {
        const add=(a,b)=>a.map((v,i)=>v+b[i]),sub=(a,b)=>a.map((v,i)=>v-b[i]),mul=(a,k)=>a.map(v=>v*k),dot=(a,b)=>a.reduce((s,v,i)=>s+v*b[i],0),cross=(a,b)=>[a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]],length=a=>Math.hypot(...a),unit=a=>mul(a,1/length(a)),lerp=(a,b,t)=>add(a,mul(sub(b,a),t));
        const h=Math.sqrt(3);
        // Equilateral bases in the XZ plane; lateral edges are perpendicular to them.
        const vertices=[[-1,-1,-h/3],[1,-1,-h/3],[0,-1,2*h/3],[-1,1,-h/3],[1,1,-h/3],[0,1,2*h/3]];
        const labels=['A','B','C','A₁','B₁','C₁'];
        const edges=[[0,1],[1,2],[2,0],[3,4],[4,5],[5,3],[0,3],[1,4],[2,5]];
        const faceFrom=(ids,name)=>{const a=vertices[ids[0]],b=vertices[ids[1]],c=vertices[ids[2]];let n=unit(cross(sub(b,a),sub(c,a)));const center=mul(ids.map(i=>vertices[i]).reduce(add,[0,0,0]),1/ids.length);if(dot(n,center)<0)n=mul(n,-1);return{ids,n,name}};
        const faces=[faceFrom([0,2,1],'ABC'),faceFrom([3,4,5],'A₁B₁C₁'),faceFrom([0,1,4,3],'ABB₁A₁'),faceFrom([1,2,5,4],'BCC₁B₁'),faceFrom([2,0,3,5],'CAA₁C₁')];
        const edgeName=i=>edges[i].map(v=>labels[v]).join('');
        function section(points){
          if(points.length!==3||points.some(p=>!p))return {type:'incomplete',polygon:[]};
          const ab=sub(points[1],points[0]),ac=sub(points[2],points[0]);
          if(length(ab)<1e-6||length(ac)<1e-6||length(sub(points[1],points[2]))<1e-6)return {type:'duplicate',polygon:[]};
          const normal=cross(ab,ac);
          if(length(normal)/(length(ab)*length(ac))<1e-6)return {type:'collinear',polygon:[]};
          const n=unit(normal),d=dot(n,points[0]),polygon=[];
          const push=p=>{if(!polygon.some(q=>length(sub(p,q))<1e-6))polygon.push(p)};
          for(const [i,j]of edges){const a=vertices[i],b=vertices[j],da=dot(n,a)-d,db=dot(n,b)-d;if(Math.abs(da)<1e-7)push(a);if(Math.abs(db)<1e-7)push(b);if(da*db<0)push(lerp(a,b,da/(da-db)))}
          if(polygon.length<3)return {type:'degenerate',polygon:[]};
          const center=mul(polygon.reduce(add,[0,0,0]),1/polygon.length),u=unit(sub(polygon[0],center)),v=cross(n,u);
          polygon.sort((a,b)=>Math.atan2(dot(sub(a,center),v),dot(sub(a,center),u))-Math.atan2(dot(sub(b,center),v),dot(sub(b,center),u)));
          return {type:'valid',polygon,n,d,center,u,v};
        }
        return {add,sub,mul,dot,cross,length,unit,lerp,vertices,labels,edges,faces,edgeName,section};
      })();

      (() => {
        const G=Geometry,{add,sub,mul,dot,cross,length,unit,lerp,vertices,labels,edges,faces}=G;
        const $=id=>document.getElementById(id),canvas=$('scene'),ctx=canvas.getContext('2d');
        if(!ctx){$('stage-title').textContent='Ваш браузер не поддерживает Canvas. Откройте сайт в современном браузере.';return}
        const names=['M','N','K'];let points=[null,null,null],selected=0,mode='edges',yaw=.65,pitch=.43,zoom=1,hover=null,cut=G.section(points),W=0,H=0,scale=1,cx=0,cy=0,basis={},drag=null,raf=0,toastTimer=0,gesture=false;
        const pointers=new Map();let pinchDistance=0;
        const clamp=(v,a,b)=>Math.max(a,Math.min(b,v));
        function camera(){basis.n=[Math.sin(yaw)*Math.cos(pitch),Math.sin(pitch),Math.cos(yaw)*Math.cos(pitch)];basis.r=[Math.cos(yaw),0,-Math.sin(yaw)];basis.u=cross(basis.n,basis.r);scale=Math.min(W/5.4,(H-185)/4.2)*zoom;cx=W/2;cy=H/2+3}
        function project(p){return{x:cx+dot(p,basis.r)*scale,y:cy-dot(p,basis.u)*scale,z:dot(p,basis.n)}}
        function resize(){const r=canvas.getBoundingClientRect(),dpr=Math.min(window.devicePixelRatio||1,2);W=r.width;H=r.height;canvas.width=Math.round(W*dpr);canvas.height=Math.round(H*dpr);ctx.setTransform(dpr,0,0,dpr,0,0);camera();requestDraw()}
        function requestDraw(){if(!raf)raf=requestAnimationFrame(()=>{raf=0;draw()})}
        function path3(poly,close=true){ctx.beginPath();poly.forEach((v,i)=>{const p=project(v);i?ctx.lineTo(p.x,p.y):ctx.moveTo(p.x,p.y)});if(close)ctx.closePath()}
        function line(a,b,color,width=1,dash=[]){path3([a,b],false);ctx.strokeStyle=color;ctx.lineWidth=width;ctx.setLineDash(dash);ctx.stroke();ctx.setLineDash([])}
        function label(text,x,y,color,size=14){if(text.endsWith('₁')){label(text.slice(0,-1),x-3,y,color,size);label('1',x+6,y+5,color,size*.7);return}ctx.font=`500 ${size}px Arial,sans-serif`;ctx.textAlign='center';ctx.textBaseline='middle';ctx.lineJoin='round';ctx.lineWidth=4;ctx.strokeStyle='#152035';ctx.strokeText(text,x,y);ctx.fillStyle=color;ctx.fillText(text,x,y)}
        function draw(){
          camera();ctx.clearRect(0,0,W,H);
          for(let i=-4;i<=4;i++){const a=i/2;line([-2,-1.03,a],[2,-1.03,a],'#a4b5e20c');line([a,-1.03,-2],[a,-1.03,2],'#a4b5e20c')}
          if(cut.type==='valid'&&$('plane').checked){const {center:c,u,v}=cut;const square=[[-1,-1],[1,-1],[1,1],[-1,1]].map(([a,b])=>add(c,add(mul(u,a*1.9),mul(v,b*1.9))));path3(square);ctx.fillStyle='#ffb08b09';ctx.fill();ctx.strokeStyle='#ffad8540';ctx.lineWidth=1;ctx.setLineDash([5,6]);ctx.stroke();ctx.setLineDash([])}
          const sortedFaces=[...faces].sort((a,b)=>dot(a.n,basis.n)-dot(b.n,basis.n));
          for(const f of sortedFaces){path3(f.ids.map(i=>vertices[i]));const facing=dot(f.n,basis.n);ctx.fillStyle=facing>0?`rgba(144,168,255,${.022+.025*facing})`:'rgba(90,115,175,.015)';ctx.fill()}
          const visible=edges.map(([a,b])=>faces.some(f=>f.ids.includes(a)&&f.ids.includes(b)&&dot(f.n,basis.n)>1e-8));
          edges.forEach(([a,b],i)=>{if(!visible[i])line(vertices[a],vertices[b],'#7f94bd69',1.1,[5,6])});
          if(cut.type==='valid'){
            path3(cut.polygon);const grad=ctx.createLinearGradient(cx-scale,cy-scale,cx+scale,cy+scale);grad.addColorStop(0,'#ffc09673');grad.addColorStop(1,'#fb885849');ctx.fillStyle=grad;ctx.fill();ctx.strokeStyle='#ffb08a';ctx.lineWidth=2.4;ctx.shadowColor='#ffad8540';ctx.shadowBlur=12;ctx.stroke();ctx.shadowBlur=0;
            for(const p of cut.polygon){const q=project(p);ctx.beginPath();ctx.arc(q.x,q.y,3.2,0,Math.PI*2);ctx.fillStyle='#ffc2a2';ctx.fill()}
          }
          edges.forEach(([a,b],i)=>{if(visible[i])line(vertices[a],vertices[b],'#b5c6eddd',1.6)});
          if(hover&&hover.edge!=null&&selected!==null)line(...edges[hover.edge].map(i=>vertices[i]),'#dcd7ff',2.7);
          const ps=vertices.map(project);
          ps.forEach((p,i)=>{ctx.beginPath();ctx.arc(p.x,p.y,2.6,0,2*Math.PI);ctx.fillStyle='#c6d3f0';ctx.fill();const dx=p.x-cx,dy=p.y-cy,dist=Math.hypot(dx,dy)||1;label(labels[i],p.x+dx/dist*19,p.y+dy/dist*19,'#c5d0e7',14)});
          if(hover&&selected!==null&&!pointers.size){const p=project(hover.p);ctx.beginPath();ctx.arc(p.x,p.y,7,0,Math.PI*2);ctx.fillStyle='#d8c8ff66';ctx.fill();ctx.strokeStyle='#d3c4ff';ctx.lineWidth=1.5;ctx.stroke();label(names[selected],p.x+15,p.y-16,'#dbcbff',14)}
          points.map((p,i)=>p?{...p,i,screen:project(p.p)}:null).filter(Boolean).sort((a,b)=>a.screen.z-b.screen.z).forEach(p=>{const {x,y}=p.screen;if(selected===p.i){ctx.beginPath();ctx.arc(x,y,12,0,Math.PI*2);ctx.strokeStyle='#ffc59e66';ctx.lineWidth=1.5;ctx.stroke()}ctx.beginPath();ctx.arc(x,y,6.3,0,Math.PI*2);ctx.fillStyle='#ffc19d';ctx.fill();ctx.lineWidth=2.5;ctx.strokeStyle='#172136';ctx.stroke();let dx=x-cx,dy=y-cy,dist=Math.hypot(dx,dy)||1;let lx=x+dx/dist*23,ly=y+dy/dist*23;if(ps.some(v=>Math.hypot(v.x-x,v.y-y)<23)){lx=x+20;ly=y+17}label(names[p.i],lx,ly,'#ffc7a5',16)});
        }
        function toast(message){$('toast').textContent=message;$('toast').classList.add('show');clearTimeout(toastTimer);toastTimer=setTimeout(()=>$('toast').classList.remove('show'),2600)}
        function edgePoint(i,t){return{p:lerp(vertices[edges[i][0]],vertices[edges[i][1]],t),edge:i,t}}
        function snapped(t){t=clamp(t,0,1);if(t<.025)return 0;if(t>.975)return 1;if($('snap').checked&&Math.abs(t-.5)<.04)return .5;return t}
        function pickEdge(x,y,only=null){let best=null;edges.forEach(([a,b],i)=>{if(only!==null&&only!==i)return;const A=project(vertices[a]),B=project(vertices[b]),dx=B.x-A.x,dy=B.y-A.y,l=dx*dx+dy*dy;if(l<2)return;const raw=clamp(((x-A.x)*dx+(y-A.y)*dy)/l,0,1),px=A.x+raw*dx,py=A.y+raw*dy,dist=Math.hypot(px-x,py-y),z=A.z+(B.z-A.z)*raw;const tolerance=drag?.point!=null?Infinity:(drag?.touch?23:16);if(dist<tolerance&&(!best||dist<best.dist-1.5||(Math.abs(dist-best.dist)<1.5&&z>best.z)))best={...edgePoint(i,snapped(raw)),dist,z}});return best}
        function insideFace(p,f){let sign=0;for(let k=0;k<f.ids.length;k++){const a=vertices[f.ids[k]],b=vertices[f.ids[(k+1)%f.ids.length]],c=cross(sub(b,a),sub(p,a)),v=dot(c,f.n);if(Math.abs(v)<1e-7)continue;const s=Math.sign(v);if(!sign)sign=s;else if(s!==sign)return false}return true}
        function pickFace(x,y,only=null){const base=add(mul(basis.r,(x-cx)/scale),mul(basis.u,-(y-cy)/scale)),origin=add(base,mul(basis.n,8)),direction=mul(basis.n,-1);let best=null;faces.forEach((f,i)=>{if(only!==null&&only!==i)return;const denom=dot(f.n,direction);if(Math.abs(denom)<1e-7)return;const planeD=dot(f.n,vertices[f.ids[0]]),t=(planeD-dot(f.n,origin))/denom;if(t<0)return;const p=add(origin,mul(direction,t));if(insideFace(p,f)&&(!best||t<best.distance))best={p,face:i,distance:t}});return best}
        function pick(x,y){return mode==='edges'?pickEdge(x,y):pickFace(x,y)}
        function hitPoint(x,y){let best=null;points.forEach((p,i)=>{if(!p)return;const q=project(p.p),d=Math.hypot(x-q.x,y-q.y);if(d<19&&(!best||d<best.d))best={i,d}});return best?.i??null}
        function assign(index,value,advance=true){if(points.some((p,i)=>i!==index&&p&&length(sub(p.p,value.p))<1e-5)){toast('Эта точка уже выбрана. Поставьте другую.');return false}points[index]=value;if(advance){const next=points.findIndex(p=>!p);selected=next<0?null:next}update();return true}
        function recalc(){cut=G.section(points.map(p=>p?.p??null))}
        function renderPoints(){
          $('points').innerHTML=points.map((p,i)=>{
            const subtitle=p?(p.edge!=null?`ребро ${G.edgeName(p.edge)}`:`грань ${faces[p.face].name}`):(selected===i?'Нажмите на куб':'Точка не выбрана');
            const main=p?'Точка '+names[i]:(selected===i?'Поставьте точку '+names[i]:'Точка '+names[i]);
            const options='<option value="">Выбрать ребро…</option>'+edges.map((_,e)=>`<option value="${e}" ${p?.edge===e?'selected':''}>${G.edgeName(e)}</option>`).join('');
            return `<div class="point-row ${selected===i?'active':''}" data-set="${!!p}"><div class="point-top"><button class="point-pick" data-select="${i}" aria-pressed="${selected===i}" aria-label="Выбрать точку ${names[i]} для перемещения"><span class="point-letter">${names[i]}</span><span><span class="point-text">${main}</span><span class="point-sub">${subtitle}</span></span></button>${p?`<button class="remove" data-remove="${i}" aria-label="Удалить точку ${names[i]}" title="Удалить точку">×</button>`:''}</div>${(selected===i||p?.edge!=null)?`<div class="edge-controls"><select class="edge-select" data-edge="${i}" aria-label="Ребро для точки ${names[i]}">${options}</select>${p?.edge!=null?`<input class="point-slider" type="range" min="0" max="100" step="1" value="${Math.round(p.t*100)}" data-slider="${i}" aria-label="Положение точки ${names[i]} на ребре в процентах"><span class="percent" id="pct-${i}">${Math.round(p.t*100)}%</span>`:''}</div>`:''}</div>`
          }).join('');
        }
        function renderResult(){
          const status=$('result-status');status.classList.remove('error');
          if(cut.type==='valid'){
            const titles={3:'Треугольник',4:'Четырёхугольник',5:'Пятиугольник',6:'Шестиугольник'};status.textContent=`${titles[cut.polygon.length]||'Многоугольник'} · ${cut.polygon.length} ${cut.polygon.length<5?'вершины':'вершин'}`;
            const local=cut.polygon.map(p=>{const q=sub(p,cut.center);return[dot(q,cut.u),dot(q,cut.v)]});
            const xs=local.map(p=>p[0]),ys=local.map(p=>p[1]),minX=Math.min(...xs),maxX=Math.max(...xs),minY=Math.min(...ys),maxY=Math.max(...ys),s=Math.min(230/(maxX-minX||1),100/(maxY-minY||1));
            const coords=local.map(([x,y])=>[140+(x-(maxX+minX)/2)*s,63-(y-(maxY+minY)/2)*s]);
            $('mini').innerHTML=`<div style="width:100%"><svg class="mini-svg" viewBox="0 0 280 126" role="img" aria-label="Плоский вид сечения: ${titles[cut.polygon.length]||'многоугольник'}"><polygon points="${coords.map(p=>p.join(',')).join(' ')}" fill="#fff1e9" stroke="#e4946c" stroke-width="1.8" stroke-linejoin="round"/>${coords.map(([x,y])=>`<circle cx="${x}" cy="${y}" r="2.8" fill="#dc8965"/>`).join('')}</svg><div class="result-foot">Вид перпендикулярно плоскости сечения</div></div>`;
          }else{
            const count=points.filter(Boolean).length;status.textContent=cut.type==='collinear'?'Точки лежат на одной прямой. Переместите одну из них.':cut.type==='duplicate'?'Точки совпадают. Выберите разные точки.':cut.type==='degenerate'?'Плоскость касается куба. Переместите точку.':count===0?'Ждём три точки':count===1?'Добавьте ещё две точки':'Добавьте третью точку';
            if(!['incomplete'].includes(cut.type))status.classList.add('error');
            $('mini').innerHTML='<div class="empty-section"><svg width="56" height="44" viewBox="0 0 56 44" fill="none" aria-hidden="true"><path d="m8 33 12-24 28 17Z" stroke="currentColor" stroke-dasharray="4 4" stroke-width="1.3"/><circle cx="8" cy="33" r="3" fill="#a9a1e4"/><circle cx="20" cy="9" r="3" fill="#a9a1e4"/><circle cx="48" cy="26" r="3" fill="#a9a1e4"/></svg>'+(cut.type==='incomplete'?'Здесь появится фигура сечения':'Три точки должны определять<br>единственную плоскость')+'</div>';
          }
        }
        function update(rebuild=true){recalc();if(rebuild)renderPoints();renderResult();const n=points.filter(Boolean).length;$('count').textContent=`${n} / 3`;$('clear').disabled=n===0;$('stage-title').textContent=selected!==null?(points[selected]?`Переместите точку ${names[selected]}`:n===0?'Поставьте первую точку':`Поставьте точку ${names[selected]}`):cut.type==='valid'?'Сечение построено':'Переместите одну из точек';requestDraw()}
        function setMode(value){mode=value;hover=null;$('mode-edges').setAttribute('aria-pressed',value==='edges');$('mode-faces').setAttribute('aria-pressed',value==='faces');$('placement-hint').textContent=value==='edges'?'Нажмите на ребро призмы. Сечение появится после третьей точки.':'Нажмите на видимую грань призмы. Сечение появится после третьей точки.';requestDraw()}
        function clear(){points=[null,null,null];selected=0;hover=null;update()}
        function example(){points=[edgePoint(0,.5),edgePoint(4,.5),edgePoint(8,.5)];selected=null;hover=null;update();toast('Пример сечения правильной треугольной призмы')}
        function setZoom(v){zoom=clamp(v,.6,1.5);requestDraw()}
        function home(){yaw=.65;pitch=.43;zoom=1;hover=null;requestDraw()}
        $('points').addEventListener('click',e=>{const button=e.target.closest('button');if(!button)return;if(button.hasAttribute('data-select')){selected=+button.dataset.select;hover=null;update()}if(button.hasAttribute('data-remove')){const i=+button.dataset.remove;points[i]=null;selected=i;update()}});
        $('points').addEventListener('change',e=>{if(e.target.hasAttribute('data-edge')&&e.target.value!==''){const i=+e.target.dataset.edge;assign(i,edgePoint(+e.target.value,.5));}});
        $('points').addEventListener('input',e=>{if(e.target.hasAttribute('data-slider')){const i=+e.target.dataset.slider,t=+e.target.value/100;points[i]=edgePoint(points[i].edge,t);$('pct-'+i).textContent=Math.round(t*100)+'%';update(false)}});
        $('mode-edges').onclick=()=>setMode('edges');$('mode-faces').onclick=()=>setMode('faces');$('example').onclick=example;$('clear').onclick=clear;$('plane').onchange=requestDraw;$('zoom-in').onclick=()=>setZoom(zoom*1.15);$('zoom-out').onclick=()=>setZoom(zoom/1.15);$('home').onclick=home;
        const xy=e=>{const r=canvas.getBoundingClientRect();return{x:e.clientX-r.left,y:e.clientY-r.top}};
        canvas.addEventListener('pointerdown',e=>{if(e.button!==0&&e.pointerType==='mouse')return;e.preventDefault();canvas.focus({preventScroll:true});const p=xy(e);pointers.set(e.pointerId,p);canvas.setPointerCapture(e.pointerId);if(pointers.size>1){gesture=true;drag=null;const a=[...pointers.values()];pinchDistance=Math.hypot(a[0].x-a[1].x,a[0].y-a[1].y);return}gesture=false;const index=hitPoint(p.x,p.y);drag={start:p,last:p,moved:false,point:index,touch:e.pointerType==='touch'};if(index!==null){selected=index;update()}hover=null;canvas.classList.add('dragging')});
        canvas.addEventListener('pointermove',e=>{const p=xy(e);if(pointers.has(e.pointerId))pointers.set(e.pointerId,p);if(pointers.size>1){const a=[...pointers.values()],d=Math.hypot(a[0].x-a[1].x,a[0].y-a[1].y);if(pinchDistance>0)setZoom(zoom*d/pinchDistance);pinchDistance=d;return}if(drag){if(Math.hypot(p.x-drag.start.x,p.y-drag.start.y)>4)drag.moved=true;if(drag.moved){if(drag.point!==null){const old=points[drag.point],next=old.edge!=null?pickEdge(p.x,p.y,old.edge):pickFace(p.x,p.y,old.face);if(next){points[drag.point]=next;update()}}else{yaw-=(p.x-drag.last.x)*.008;pitch=clamp(pitch+(p.y-drag.last.y)*.008,-1.4,1.4);requestDraw()}}drag.last=p;return}if(!pointers.size){hover=selected!==null?pick(p.x,p.y):null;canvas.classList.toggle('placing',!!hover||hitPoint(p.x,p.y)!==null);requestDraw()}});
        function release(e,canceled=false){const old=drag;pointers.delete(e.pointerId);if(canvas.hasPointerCapture(e.pointerId))canvas.releasePointerCapture(e.pointerId);canvas.classList.remove('dragging');if(!canceled&&!gesture&&old&&!old.moved&&old.point===null){const p=xy(e);if(selected===null){toast('Выберите M, N или K в панели, чтобы переставить точку.')}else{const candidate=pick(p.x,p.y);if(candidate)assign(selected,candidate);else toast(mode==='edges'?'Нажмите ближе к ребру призмы.':'Нажмите на видимую грань призмы.')}}drag=null;if(!pointers.size){gesture=false;pinchDistance=0}hover=null;requestDraw()}
        canvas.addEventListener('pointerup',e=>release(e));canvas.addEventListener('pointercancel',e=>release(e,true));canvas.addEventListener('pointerleave',()=>{hover=null;requestDraw()});
        canvas.addEventListener('wheel',e=>{e.preventDefault();setZoom(zoom*Math.exp(-e.deltaY*.001))},{passive:false});
        canvas.addEventListener('keydown',e=>{const actions={ArrowLeft:()=>yaw-=.12,ArrowRight:()=>yaw+=.12,ArrowUp:()=>pitch=clamp(pitch+.12,-1.4,1.4),ArrowDown:()=>pitch=clamp(pitch-.12,-1.4,1.4),'+':()=>setZoom(zoom*1.1),'=':()=>setZoom(zoom*1.1),'-':()=>setZoom(zoom/1.1),'0':home,Escape:()=>{selected=null;hover=null;update()}};if(actions[e.key]){e.preventDefault();actions[e.key]();requestDraw()}});
        new ResizeObserver(resize).observe(canvas);update();resize();
        const state=()=>({points:points.map((p,i)=>p?{name:names[i],coordinates:p.p,edge:p.edge!=null?G.edgeName(p.edge):null}:null),section:{status:cut.type,vertices:cut.polygon}});
        // The optional browser tool uses exactly the same points and rendering as the UI.
        const modelContext=document.modelContext;
        if(modelContext?.registerTool){const lifecycle=new AbortController();try{Promise.resolve(modelContext.registerTool({name:'set_triangular_prism_section',title:'Построить сечение треугольной призмы',description:'Разместить ровно три точки на рёбрах правильной треугольной призмы и построить сечение. Координата t задаёт долю ребра от первой вершины.',inputSchema:{type:'object',properties:{points:{type:'array',minItems:3,maxItems:3,items:{type:'object',properties:{edge:{type:'integer',minimum:0,maximum:8},t:{type:'number',minimum:0,maximum:1}},required:['edge','t'],additionalProperties:false}}},required:['points'],additionalProperties:false},annotations:{readOnlyHint:false,untrustedContentHint:false},execute(input){if(!input||!Array.isArray(input.points)||input.points.length!==3||!input.points.every(p=>p&&Number.isInteger(p.edge)&&p.edge>=0&&p.edge<9&&Number.isFinite(p.t)&&p.t>=0&&p.t<=1))throw new Error('Нужны три точки с edge от 0 до 8 и t от 0 до 1. Порядок рёбер: AB, BC, CA, A₁B₁, B₁C₁, C₁A₁, AA₁, BB₁, CC₁.');const next=input.points.map(p=>edgePoint(p.edge,p.t));const computed=G.section(next.map(p=>p.p));if(computed.type!=='valid')throw new Error('Точки должны быть различными и не лежать на одной прямой.');points=next;selected=null;hover=null;update();return state()}},{signal:lifecycle.signal})).catch(()=>{});window.addEventListener('pagehide',()=>lifecycle.abort(),{once:true})}catch{/* Optional API is not required for normal interaction. */}}
      })();
      </script>
      </body>
      </html>)";
}
