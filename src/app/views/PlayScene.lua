local PlayScene = class("PlayScene", cc.load("mvc").ViewBase)

function PlayScene:onCreate()

     -- add HelloWorld label
    cc.Label:createWithSystemFont("Hello World", "Arial", 40)
        :move(display.cx, display.cy)
        :addTo(self)
		
end

return PlayScene
