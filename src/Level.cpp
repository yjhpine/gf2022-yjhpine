#include "Level.h"
#include "assets.h"
#include "tmxlite/Map.hpp"
#include "tmxlite/Layer.hpp"
#include "tmxlite/TileLayer.hpp"
#include <iostream>
#include <algorithm>

tile::tile(SDL_Texture* tset, int x, int y, int tx, int ty, int w, int h)
    : sheet(tset), x(x), y(y), tx(tx), ty(ty), width(w), height(h) {

}

void tile::draw(SDL_Renderer* ren) {
    if (!ren || !sheet)
        return;

    SDL_Rect src;
    src.x = tx;
    src.y = ty;
    src.w = width;
    src.h = height;

    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = src.w;
    dest.h = src.h;

    SDL_RenderCopy(ren, sheet, &src, &dest);
}

level::level(const std::string& name)
    : name(name), rows(0), cols(0) {

}

void level::load(const std::string& path, SDL_Renderer* ren) {
    tmx::Map tiled_map;
    tiled_map.load(path);

    auto map_dimensions = tiled_map.getTileCount();
    rows = map_dimensions.y;
    cols = map_dimensions.x;

    auto tilesize = tiled_map.getTileSize();
    tile_width = tilesize.x;
    tile_height = tilesize.y;

    auto& map_tilesets = tiled_map.getTilesets();
    for (auto& tset : map_tilesets) {
        auto tex = assets::instance()
            .load_texture(tset.getImagePath(), ren);
        tilesets.insert(std::pair<gid, SDL_Texture*>(tset.getFirstGID(), tex));
    }

    auto& map_layers = tiled_map.getLayers();
    for (auto& layer : map_layers) {
        if (layer->getType() != tmx::Layer::Type::Tile) {
            continue;
        }
        auto* tile_layer = dynamic_cast<const tmx::TileLayer*>(layer.get());
        auto& layer_tiles = tile_layer->getTiles();
        for (auto y = 0; y < rows; ++y) {
            for (auto x = 0; x < cols; ++x) {
                auto tile_index = x + (y * cols);
                auto cur_gid = layer_tiles[tile_index].ID;
                if (cur_gid == 0) {
                    continue;
                }
                auto tset_gid = -1;
                for (auto& ts : tilesets) {
                    if (ts.first <= cur_gid) {
                        tset_gid = ts.first;
                        break;
                    }
                }
                if (tset_gid == -1) {
                    continue;
                }

                cur_gid -= tset_gid;

                auto ts_width = 0;
                auto ts_height = 0;
                SDL_QueryTexture(tilesets[tset_gid],
                    NULL, NULL, &ts_width, &ts_height);

                auto region_x = (cur_gid % (ts_width / tile_width)) * tile_width;
                auto region_y = (cur_gid / (ts_width / tile_width)) * tile_height;

                auto x_pos = x * tile_width;
                auto y_pos = y * tile_height;

                tile t(tilesets[tset_gid], x_pos, y_pos,
                    region_x, region_y, tile_width, tile_height);
                tiles.push_back(t);
            }
        }
    }
}

void level::draw(SDL_Renderer* ren) {
    for (auto& tile : tiles) {
        tile.draw(ren);
    }
}