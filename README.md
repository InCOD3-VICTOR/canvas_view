# canvas_view

基于duilib的白板工具，可适用用教育行业或者是视频会议的演示白板

设计之初就是想实现类似于玻璃的一样的白板，透明，但是可以添加自己需要的工具，这样做的好处在于：
1 这块“玻璃”可以覆盖在任何窗口的上面，而且不用关心“玻璃”下面是什么东西，这样就可以将任何的内容放在玻璃板下面。 
2 玻璃提供穿透的功能，可以将鼠标的事件完全回调给下层窗口，不影响下层窗口的使用。

这个版本的工具实现了以下功能
1 常规的图形（矩形，椭圆，直线，箭头，三角形，菱形）
2 图形的二次编辑（移动，删除，添加）
3 图形保存功能，通过序列化反序列化可以将图形保存成json
4 由于本窗口是透明窗口，可以覆盖在其他的窗口上面，实现标注功能

测试demo没有写太详细，可以自己摸索
