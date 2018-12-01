# Doodle_Jump<br />
本项目是模仿涂鸦跳跃的一款安卓游戏，新手项目，多多包涵，如有bug、建议请反馈至ginray0215@gmail.com&nbsp; 。<br />
<br />
<br />
5/27 <br />
&nbsp;&nbsp; &nbsp;日志：&nbsp;&nbsp; &nbsp;<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;上传了Doodle_Jump项目；<br />
&nbsp;&nbsp; &nbsp;现有bug：<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;当主角过屏幕1/2的时候会出现明显卡顿，此时踏板和主角都不会刷新，应该是少画了一帧，但未能找到出错的代码；<br />
&nbsp;&nbsp;&nbsp; &nbsp;未实现功能：<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;1、未绘制怪兽，完成相关的游戏逻辑；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;2、主角未能实现发射子弹的功能；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;3、未实现暂停功能（包括游戏在切换出去之后返回会把游戏重新加载）；<br />
5/28<br />
&nbsp;&nbsp; &nbsp;日志：<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;修复bug；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;在函数DoodleJumpView中<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;try {<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;mGameUi.updateGameUi();<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;c = mSurfaceHolder.lockCanvas(null);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;synchronized (mSurfaceHolder) {<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;doDraw(c);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;handleEffect(mGameUi.getEffectFlag());<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;} catch (Exception e) {<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;System.out.println(&quot;Canvas&quot;+e);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;Log.e(&quot;Canvas&quot;, &quot;Error&quot;);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;} finally {<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;/*<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 这里会发生ConcurrentModificationException错误而导致c有可能是null；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 这个bug调试了一周多，真是醉了；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 关于ConcurrentModificationException:<br />
<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 文档中说明，对Vector、ArrayList在迭代的时候如果同时<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 对其进行修改就会抛出java.util.ConcurrentModificationException异常。<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 因为我在GameUi 中使用了一个&nbsp;&nbsp; &nbsp;LinkedList 在updateGameUi()的时候<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 访问了两次的LinkedList造成了这个错误,然而我并没有remove&nbsp; 也没有使用多线程；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 因此这个报错就显得非常蛋疼，让我一阵不知所措;<br />
<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; javadoc 里面指出： it would be wrong to write a program that depended<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; on this exception for its correctness: ConcurrentModificationException<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; should be used only to detect bugs.<br />
<br />
<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; 说人话就是&nbsp; 这个应该用于发bug的东西变成了一个bug，困扰了我一周多；<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp; ！！！！！<br />
<br />
<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;* */<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;//if (c != null)<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;mSurfaceHolder.unlockCanvasAndPost(c);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;Log.v(&quot;Canvas&quot;,&quot;draw&quot;);<br />
&nbsp;&nbsp; &nbsp;&nbsp;&nbsp; &nbsp;}